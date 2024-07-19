#!/bin/bash
# Dan Mocnik
# Created: 11/29/2023
# Logs CPU and Memory usage to cpu_memory.log

date=$(date)
memory=$(free | grep Mem | awk '{print $3/$2 * 100.0 "%"}')
cpu=$(top -bn2 | grep '%Cpu' | tail -1 | grep -P '(....|...) id,'|awk '{print 100-$8 "%"}')

echo ${date} - CPU usage: ${cpu} >> /home/danoman154/cpu_memory.log
echo ${date} - Memory usage: ${memory} >> /home/danoman154/cpu_memory.log

