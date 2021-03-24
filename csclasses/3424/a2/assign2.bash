#!/bin/bash

for file in "$@"; do
	sed -i -f assign2.sed "$file"
done
