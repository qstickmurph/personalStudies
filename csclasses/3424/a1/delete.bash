delete () {

	while read -p "Photo Number(1-99999): " photoNum; do
		if [ ! -e data/p${photoNum}.photo ]; then
			echo "p${photoNum}.photo does not exist"
			continue
		fi
		break
	done
	
	rm data/p${photoNum}.photo
	printf "`date \"+[%Y-%m-%d %H:%M:%S]\"` DELETED: ${photoNum}\n" >> data/queries.log

}
