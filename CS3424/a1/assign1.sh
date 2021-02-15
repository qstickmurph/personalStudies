#!/bin/bash
source ./create.bash
source ./read.bash
source ./update.bash
source ./delete.bash


echo "Enter one of the following actions or press CTRL-D to exit."
echo ""
echo "C - create a new photo item"
echo ""
echo "R - read an existing photo item"
echo ""
echo "U - update an existing photo item"
echo ""
echo "D - delete an existing photo item"
echo ""
echo "Q - quit"

while read -p "> " entry; do
	
	if [[ "$entry" =~ [Cc] ]]; then
		create

	elif [[ "$entry" =~ [Rr] ]]; then
		readPhoto

	elif [[ "$entry" =~ [Uu] ]]; then
		update

	elif [[ "$entry" =~ [Dd] ]]; then
		delete

	elif [[ "$entry" =~ [Qq] ]]; then
		echo "You pressed Q"
		break
	else
		echo "ERROR: invalid option: '${entry}'"
		continue
	fi
 	
	echo ""
	echo "Enter one of the following actions or press CTRL-D to exit."
	echo ""
	echo "C - create a new photo item"
	echo ""
	echo "R - read an existing photo item"
	echo ""
	echo "U - update an existing photo item"
	echo ""
	echo "D - delete an existing photo item"
	echo ""
	echo "Q - quit"

done
