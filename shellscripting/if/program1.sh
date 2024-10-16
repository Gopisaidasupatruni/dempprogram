#!/bin/bash
read -p "Enter a number: " n
if [ $n -gt 0 ]; then
	echo " $n is positive "
else
	echo " $n is negative "
fi

