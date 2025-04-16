import PyInstaller.__main__

PyInstaller.__main__.run([
    '--onefile',
    '--name=InventoryApp',
    '--console',
    '--icon=inv.ico',
    'inv_script.py',
])