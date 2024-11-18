#!/bin/bash
if [ $# -ne 2 ]
then
echo enter two files 
exit 1	
fi

if [ ! -f $1 ] || [ ! -f $2 ]  
then
echo "file doesnt exits"
else
	echo "exists"
fi
