#!/bin/bash
#checking shopt is enabled or not
if shopt -q nocasematch
then
	echo nocase
fi
#enabling shopt
shopt -s nocasematch
read -p "Enter a color red, green, or blue: " color
case $color in
    red) echo "selected RED" ;;
    green) echo "selected GREEN" ;;
    blue) echo "selected BLUE" ;;
    *) echo "Invalid color" ;;
esac

shopt -u nocasematch
#end
