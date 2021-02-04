let index=0
let undivis=0

while read line; do
	let index=(index + 1)
	if [ $(( index % 3 )) -eq 0 ]; then
		echo $line
	else
		let undivis=(undivis+1)
	fi
done

if [ $undivis -gt 10 ]; then
	echo big
else
	echo small
fi
