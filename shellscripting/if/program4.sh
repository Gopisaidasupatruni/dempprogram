#!/bin/bash
read -p "Enter a number: " n
if [ $n -ge 0 ]; then
	echo " greater then or equals to 0  "
if [ $n -gt 5 ]; then
	echo " greater than 5 "
else
	echo " less than 5 "
fi
else
	echo " negative "
fi
