#!/bin/bash

if [ -z "$1" ]; then
    rental="**unknown**"
else
    rental="$1"
fi

case $rental in
    "car") echo "The rent for car is 10 dollars";;
    "van") echo "The rent for van is 20 dollars";;
    *) echo "Invalid input";;
esac

