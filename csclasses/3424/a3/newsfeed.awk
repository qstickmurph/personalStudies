BEGIN { 
        print "\t\t  Incoming News Feed Summary"
        print ""
    }

FNR==1 {
        startMonth = $1
        startDay = $2
        startTime = $3
    }

FNR==NR {
        endMonth = $1
        endDay = $2
        endTime = $3
    }

$4 ~ /[\+jc]/ {
        accepted[$5] += 1
        if( match($4, "c") )
            canceled[$5] += 1
        feeds[$5] = 0
    }

$4 ~ /-/ {
        rejected[$5] += 1
        feeds[$5] = 0
    }

END {
        printf("%15s%10s%10s%10s\n", "", "accepted", "rejected", "canceled")
        for(key in feeds){
            printf("%15s%10s%10s%10s\n", key, accepted[key], rejected[key], canceled[key])
        }
        print ""
        printf("Start Time = %s %s %s\t End Time = %s %s %s\n", startMonth, startDay, startTime, endMonth, endDay, endTime)
    }
