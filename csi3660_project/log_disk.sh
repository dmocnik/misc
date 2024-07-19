#!/bin/bash
# Dan Mocnik
# Created: 11/29/2023
# Logs disk usage to disk.log

date=$(date)
percent=$(sudo df -hl | grep '/dev/root' | awk '{print $5}')
used=$(sudo df -hl | grep '/dev/root' | awk '{print $3}')
free=$(sudo df -hl | grep '/dev/root' | awk '{print $4}')

echo "${date} - Disk is ${percent} full. (${used} of ${free})" >> /home/danoman154/disk.log
