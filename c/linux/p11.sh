#!/bin/bash
if [ $# -ne 4 ]
then
echo enter four parameters
exit 1
fi
one=$1
two=$2
three=$3
four=$4
echo "$four $three $two $one"
#echo $1 $2 $3 $4 | rev
