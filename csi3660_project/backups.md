# Automatic Backups

The `backup_script.sh` script is in charge of periodically backing up all of the data in `/var/www/nextcloud/data`, which is where the files that are uploaded to the users' Nextcloud accounts are stored.
The intent is to have a "time machine"-esque backup so that if Nextcloud were to malfunction, or a user were to erroneously delete a file, the file(s) can still be retreived later from a different location.
The script runs every hour and is triggered by a cron job.
The script will name the file as `backup_{YEAR}_{MONTH}_{DAY}_{HOUR}_{MINUTE}.tar.gz` in `/usr/local/CSI3660ProjectBackup`.
It will also keep the 5 most recent backups, and delete the oldest one.
