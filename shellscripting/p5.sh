#!/bin/bash
read -p " Enter a number: " n1
for ((i=1; i<=10; i++))
do
	ans=$((n1*i))
	echo "$n1 * $i = $ans"
done
