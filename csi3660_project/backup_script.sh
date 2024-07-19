#!/bin/bash

# Dan Mocnik
# Created: 11/28/2023
# To learn more, read the README at /usr/local/CSI3660ProjectBackup/README.md

# Create the filename that the backup will be stored in
current_date=`date +"%Y_%m_%d_%H_%M"`
filename="backup_"${current_date}".tar.gz"

# Tar it
tar -czvf ${filename} /var/www/nextcloud/data/

# Move it to /usr/local/CSI3660ProjectBackup
mkdir -p /usr/local/CSI3660ProjectBackup
mv ${filename} /usr/local/CSI3660ProjectBackup/

# Check how many backed up files there are
count=$(ls -l /usr/local/CSI3660ProjectBackup/*.tar.gz | wc -l)

# If there is more than 5, delete the oldest one
if [ $count -gt 5 ]
then
	oldest_file=$(find /usr/local/CSI3660ProjectBackup/*.tar.gz -type f -printf '%p\n' | sort | head -n 1)
	rm ${oldest_file}
fi
