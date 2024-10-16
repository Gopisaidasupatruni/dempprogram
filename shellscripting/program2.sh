#!/bin/bash
PASS=/etc/passwd
read -p "Enter user: " user
grep "^$user" $PASS > /dev/null

status=$?
if test $status -eq 0
then
	echo "found"
else
	echo "not found"
fi
