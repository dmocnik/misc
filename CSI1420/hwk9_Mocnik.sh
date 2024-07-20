#!/bin/bash
echo "---Problem 1---"
echo "Enter the year"
read year
echo "Enter your favorite vacation spot"
read vacation
let year++
echo "Hopefully $year will be better and you can visit $vacation"
echo


echo "---Problem 2---"
let ans1=$1*$2
let ans2=$1+$3
echo "$1 multiplied by $2 is $ans1"
echo "The sum of $1 and $3 is $ans2"
echo


echo "---Problem 3---"
hour=$(TZ=":US/Eastern" date +"%H")
minute=$(TZ=":US/Eastern" date +"%M")
ampm="AM"
if [ $minute -ge 12 ]
then
    let hour=hour-12
    ampm="PM"
fi
echo "Time is $hour:$minute $ampm"
echo


echo "---Problem 4---"
#!/bin/bash
for i in {2..100..2}
do
    let sum=sum+i
done
echo "The sum of even numbers betwen 1 and 100 is $sum"
echo


echo "---Problem 5---"
ls -l
mkdir Mocnik
cd Mocnik
pwd
cal > cal.txt
ls -l
cat cal.txt