# Inventory App

This is a simple Python-based application to collect basic information & specs about a Windows computer.
The idea is that this app can be easily put in an accessible location (such as a flash drive or network share) to quickly log the basic info about the computer to a text file, for inventory purposes (like audits or new computer set-ups).
The app will create a text file on the Desktop with the following:

- Hostname
- Serial Number
- Manufacturer
- Model
- Form Factor
- CPU
- RAM (in GB)
- MAC Addresses of all attached network devices
- Usernames that have logged onto the computer
- Domain or Workgroup
- Windows Version (including feature update and build number)

The app will also ask if you would like to upload the file to a network share.

## Customization & Usage

First, the app has to be built to a `.exe` file with [PyInstaller](https://pyinstaller.org/). This can be done by doing the following:

1. Install [Python](https://www.python.org/downloads/)
2. Install PyInstaller by running `pip install pyinstaller` in a terminal
3. Configure the app by editing lines 9 - 11 in `inv_script.py`.  Be sure to use a literal backslash `\\` to avoid escape characters
    - `UPLOAD_SERVER` - IP address or hostname of network share to upload to, e.g. `'\\myshare.net\\Sharename'`
    - `UPLOAD_PATH`- Filepath in the the share, e.g. `'\\inventory\\TO BE ADDED'`
    - `IGNORED_USERS` - List of users to prevent being written to text file, such as admin accounts, operator accounts, e.g. `['User1', 'AdminUser', 'User2']`
4. In the same directory as the script, run `python build.py` in a terminal. (If you are in VS Code, you can also press Control + Shift + B to run the build task)
5. PyInstaller will build the script to a standalone and portable `.exe`. That's it!

When you are ready run the app, simply run it on a target computer, and it will do the rest. The text file will be created at the following path: `C:\Users\[user]\Desktop\[Serial number] - [Hostname].txt`. When it has completed the process, it will prompt you about uploading the text file to the share you configured previously. If you answer "y", the script will check to see if it has access to the configured path. If it does, it will upload the file to the path, and if it does not, it will allow you to enter your credentials for the share, then upload the file.