readFile () {
	read photo
	read year month day
	read location
	read names
}

update () {
	while read -p "Photo Number(1-99999): " photoNum; do
		if [ ! -e data/p${photoNum}.photo ]; then
			echo "p${photoNum}.photo does not exist"
			continue
		fi
		break
	done
	
	readFile < "data/p${photoNum}.photo"

	while read -p "Photo Year(1950-2050): " photoYear; do
		if [ -z "${photoYear}" ]; then break; fi
		if [ ! ${photoYear} -ge 1950 -o ! ${photoYear} -le 2050 ]; then
			echo "Please enter a number between 1950 and 2050"
			continue
		fi
		year=${photoYear}
		break
	done
	
	while read -p "Photo Month(1-12): " photoMonth; do
		if [ -z "${photoMonth}" ]; then break; fi
		if [ ! ${photoMonth} -ge 1 -o ! ${photoMonth} -le 12 ]; then
			echo "Please enter a number between 1 and 12"
			continue
		fi
		month=${photoMonth}
		break
	done
	
	while read -p "Photo Day(1-31): " photoDay; do
		if [ -z "${photoDay}" ]; then break; fi
		if [ ! ${photoDay} -ge 1 -o ! ${photoDay} -le 31 ]; then
			echo "Please enter a number between 1 and 31"
			continue
		fi
		day=${photoDay}
		break
	done
	
	read -p "Photo Location: " photoLocation
	if [ -n "${photoLocation}" ]; then location=${photoLocation}; fi
	read -p "Photo Names: " photoNames
	if [ -n "${photoNames}" ]; then names=${photoNames}; fi
	
	printf "${photo}\n${year} ${month} ${day}\n${location}\n${names}" > data/p${photoNum}.photo
	printf "`date \"+[%Y-%m-%d %H:%M:%S]\"` UPDATED: ${photoNum} - ${photo} - ${month}/${day}/${year} - ${location} - ${names}\n" >> data/queries.log
}
