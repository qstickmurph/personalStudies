BEGIN {
	sum = 0;
}

/^Income/ { sum += $3 }
/^Interest/ { sum += $2 + $4 }
/^Expense/ { sum -= $5 }

END {
	print "Total =", sum;
}
