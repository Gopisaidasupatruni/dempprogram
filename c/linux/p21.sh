#!/bin/bash
read -p"enter a number" n1

read -p"enter another number" n2

sum=$((n1+n2))
let product="$n1*$n2"
echo -e "sum is:$sum \n product is $product "
