#!/bin/bash
hour=$(TZ=":US/Eastern" date +"%H")
minute=$(TZ=":US/Eastern" date +"%M")
ampm="AM"
if [ $minute -le 12 ]
then
    let hour=hour-12
    ampm="PM"
fi
echo "Time is $hour:$minute $ampm"