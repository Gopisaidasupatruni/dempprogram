#!/bin/bash
read -p"enter a number" n1
if [ $n1 -gt 0 -a $n1 -le 100 ]
then
echo sum and product are:
else
        echo wrong number
        exit 1
fi
read -p"enter another number" n2


sum=$((n1+n2))
let product="$n1*$n2"
echo -e "sum is:$sum \n product is $product "
