import os
from time import sleep
from subprocess import check_output, call
from sys import exit
from shutil import copy
from datetime import datetime
from chassis import chassis_types

UPLOAD_SERVER = '' #IP address or hostname of network share to upload to, e.g. '\\myshare.net\Sharename'
UPLOAD_PATH = '' #filepath in the the share, e.g. '\\inventory\\TO BE ADDED'
IGNORED_USERS = [] # list of users to ignore in the C:\Users directory

# Run a powershell commmand, return the output of the command as a string
def powershell(cmd: str):
    output = check_output(["powershell", "-Command", cmd], text=True)
    return output.strip().splitlines()

print('''  _    _          _   _         
 | |  | |        | | | |        
 | |__| |   ___  | | | |   ___  
 |  __  |  / _ \ | | | |  / _ \ 
 | |  | | |  __/ | | | | | (_) |
 |_|  |_|  \___| |_| |_|  \___/ 
''')
print("from the inventory app!\n")

# Get basic PC info: Hostname, CPU, serial number, Manufacturer, model, RAM, Form factor, Domain, Windows Ver
print("Getting basic info...")
info_keys = ['hostname', 'cpu', 'serial_number', 'manufacturer', 'model', 'ram_gb', 'chassis_id', 'domain', 'windows_caption', 'display_version', 'build_number']
data = powershell('''hostname
(Get-CimInstance -ClassName Win32_Processor).Name
(Get-CimInstance -ClassName Win32_Bios).SerialNumber
(Get-CimInstance -ClassName Win32_ComputerSystem).Manufacturer
(Get-CimInstance -ClassName Win32_ComputerSystem).Model
(Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum).sum /1gb
(Get-CimInstance -ClassName Win32_SystemEnclosure).ChassisTypes
(Get-CimInstance -ClassName Win32_ComputerSystem).Domain
(Get-WmiObject -class Win32_OperatingSystem).Caption
(Get-ItemProperty -Path 'HKLM:/SOFTWARE/Microsoft/Windows NT/CurrentVersion').DisplayVersion
(Get-CimInstance -ClassName Win32_OperatingSystem).BuildNumber
''') #one large multi-line PS command
basic_info = dict(zip(info_keys, data))

# Get the MACs of all the network interfaces
print('Getting MAC addresses...')
macs = powershell('foreach ($adapter in Get-NetAdapter) {Write-Output $adapter.MacAddress}')
descs = powershell('foreach ($adapter in Get-NetAdapter) {Write-Output $adapter.InterfaceDescription}')
names = powershell('foreach ($adapter in Get-NetAdapter) {Write-Output $adapter.Name}')

macs = ['N/A              ' if mac == '' else mac.replace('-', ':') for mac in macs] # format the MAC data into a more readable string
macs_formatted = ''
longest_name = max(len(name) for name in names)
for name, mac, desc in zip(names, macs, descs): #left justified table
    padded = name.ljust(longest_name, '.') 
    macs_formatted += f'  {padded}: {mac} [{desc}]\n'

# Get all the users who have logged into the PC
print('Getting users...')
ignored_users = ['All Users', 'Default', 'Default User', 'Public']
ignored_users.extend(IGNORED_USERS)
users = [item for item in os.listdir('C:\\Users') if os.path.isdir('C:\\Users\\' + item)]
unignored_users = [i for i in users if i not in ignored_users]
if len(unignored_users) == 0:
    unignored_users.append('None')

# Determine path of text file
# C:\Users\[user]\Desktop\[Serial number] - [Hostname].txt
user_dir = os.path.expanduser('~')
filename = f'{basic_info["serial_number"]} - {basic_info["hostname"]}.txt'
filepath = user_dir + r'\Desktop\\' + filename

# Assemble the string
output_string = f'''Computer Name: {basic_info["hostname"]}
Serial Number: {basic_info["serial_number"]}
Manufacturer: {basic_info["manufacturer"]}
Model: {basic_info["model"]}
Form Factor: {chassis_types[basic_info["chassis_id"]]}
CPU: {basic_info["cpu"]}
RAM: {basic_info["ram_gb"]} GB
MAC Address(es): 
{macs_formatted}
Users: {', '.join(unignored_users)}
Domain/Workgroup: {basic_info["domain"]}
Windows Version: {basic_info["windows_caption"]} v{basic_info["display_version"]} ({basic_info["build_number"]})
Created: {datetime.now().strftime("%m/%d/%Y %H:%M:%S")}
'''

print('Creating text file...\n')
with open(filepath, 'w') as txt:
    txt.write(output_string)

print(output_string)

print(f'Done! Upload to {UPLOAD_SERVER}? (y/n) ')

valid = False
while not valid:
    answer = input().lower()
    if (answer == 'y' or answer == 'n'):
        valid = True
    else:
        print('Try again')

if answer == 'n':
    print('Goodbye!')
    sleep(1)
    exit()
elif answer == 'y':
    pass

if not (os.path.exists(f'\\\\{UPLOAD_SERVER}{UPLOAD_PATH}')):
    print('Cannot access the share!')
    success = False
    while not success:
        exit_code = None
        print('Enter your credentials: \n')
        username = input('Username: ')
        exit_code = call(f'net use \\\\{UPLOAD_SERVER} /user:{username}')
        if exit_code != 0:
            print('Invalid credentials... try again')
        else:
            success = True

copy(filepath, f'\\\\{UPLOAD_SERVER}{UPLOAD_PATH}')
print('Done!')
sleep(1)
exit()