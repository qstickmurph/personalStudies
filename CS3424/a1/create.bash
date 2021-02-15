#!/bin/bash

create () {
	photoNum=""
	while read -p "Photo Number(1-99999): " photoNum; do
		if [ -z "${photoNum}" ]; then continue; fi
		if [ ! ${photoNum} -ge 1 -o ! ${photoNum} -le 99999 ]; then
			echo "Please enter a number between 1 and 99999"
			continue
		fi
		if [ -e data/p${photoNum}.photo ]; then
			echo "p${photoNum}.photo already exists"
			continue
		fi
		break
	done

	while read -p "Photo File Location: " fileLoc; do
		if [ -z "${fileLoc}" ]; then continue; fi
		if [ ! -e ${fileLoc} ]; then
			echo "${fileLoc} does not exist"
			continue
		fi
		break
	done
	
	photoYear=""
	while read -p "Photo Year(1950-2050): " photoYear; do
		if [ -z "${photoYear}" ]; then continue; fi
		if [ ! ${photoYear} -ge 1950 -o ! ${photoYear} -le 2050 ]; then
			echo "Please enter a number between 1950 and 2050"
			continue
		fi
		break
	done
	
	photoMonth=""
	while read -p "Photo Month(1-12): " photoMonth; do
		if [ -z "${photoMonth}" ]; then continue; fi
		if [ ! ${photoMonth} -ge 1 -o ! ${photoMonth} -le 12 ]; then
			echo "Please enter a number between 1 and 12"
			continue
		fi
		break
	done
	
	photoDay=""
	while read -p "Photo Day(1-31): " photoDay; do
		if [ -z "${photoDay}" ]; then continue; fi
		if [ ! ${photoDay} -ge 1 -o ! ${photoDay} -le 31 ]; then
			echo "Please enter a number between 1 and 31"
			continue
		fi
		break
	done
	
	while read -p "Photo Location: " photoLocation; do
		if [ -z "${photoLocation}" ]; then continue; fi
		break
	done
	read -p "Photo Names: " photoNames

	if [ ! -d "./data" ]; then mkdir data; fi
	printf "${fileLoc}\n${photoYear} ${photoMonth} ${photoDay}\n${photoLocation}\n${photoNames}" > data/p${photoNum}.photo
	printf "`date \"+[%Y-%m-%d %H:%M:%S]\"` CREATE: ${photoNum} - ${fileLoc} - ${photoMonth}/${photoDay}/${photoYear} - ${photoLocation} - ${photoNames}\n" >> data/queries.log
}
