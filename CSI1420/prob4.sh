#!/bin/bash
#sum=0
for i in {2..100..2}
do
    let sum=sum+i
done
echo "The sum of even numbers betwen 1 and 100 is $sum"