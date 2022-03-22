#!/bin/bash

IFS=$'\n'
for f in $(find . -name "*.xopp"); do
	echo "Attempting xournalpp -p \"$(echo "$f" | sed -e 's/.xopp$/.pdf/g' -e 's/^\.\/xoppFiles\//\.\/exportedPdfs\//g')\" \""$f"\""
	xournalpp -p $(echo "$f" | sed -e 's/.xopp$/.pdf/g' -e 's/^\.\/xoppFiles\//\.\/exportedPdfs\//g') "$f" > /dev/null
	#if [ $? -eq 0 ]; then
	#	echo "Success"
	#else
	#	echo "Failed"
	#fi
done
unset IFS
