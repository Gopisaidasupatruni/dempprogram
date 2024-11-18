#!/bin/bash
read -p "Enter a number: " n1

if [ "$n1" -le 0 ] || [ "$n1" -gt 100 ]; then
    echo "Wrong number"
    exit 1
fi
read -p"enter another number" n2


sum=$((n1+n2))
let product="$n1*$n2"

if [ $sum -eq $product ]
then
        echo sum and product are equal
fi
echo -e "sum is:$sum \n product is $product "
