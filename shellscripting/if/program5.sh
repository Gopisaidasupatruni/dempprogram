#!/bin/bash
read -p "Enter a number: " n
if [ $n -ge 0 -a $n -lt 5 ]; then
	echo " greater then or equals to 0  "
elif [ $n -gt 5 ]; then
	echo " greater than 5 "

else
	echo " negative "
fi
