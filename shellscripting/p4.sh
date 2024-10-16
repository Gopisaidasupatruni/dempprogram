#!/bin/bash
read -p " Enter a number: " n1
i=1
while [ $i -le 10 ]
do
	ans=$((n1*i))
	echo "$n1 * $i = $ans"
	i=$((i+1))
done
