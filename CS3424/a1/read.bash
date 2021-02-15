printFile () {
	read photo
	read year month day
	read location
	read names
	
}

readPhoto () {
	while read -p "Photo Number(1-99999): " photoNum; do
		if [ ! -e data/p${photoNum}.photo ]; then
			echo "p${photoNum}.photo does not exist"
			continue
		fi
		break
	done
	
	printFile < "data/p${photoNum}.photo"
	
	echo "Photo: ${photoNum}"
	echo "File: ${photo}"
	echo "Date: ${month} / ${day} / ${year}"
	echo "Location: ${location}"
	echo "Names: ${names}"

}
