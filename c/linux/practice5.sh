#!/bin/bash
let i=0
if ls *.c 1> /dev/null 2>&1;
then
for tmp in *.c
do

let i=i+1 
done
echo count of  files are $i
fi
