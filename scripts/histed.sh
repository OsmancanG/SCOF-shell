if [ $# -ne 3 ]  
then
	echo "Wrong usage. Usage: histed [time-format] [time] [command]"
	exit
fi
declare -A months
months[0]=Jan
months[1]=Feb 
months[2]=Mar 
months[3]=Apr
months[4]=May
months[5]=Jun
months[6]=Jul
months[7]=Aug
months[8]=Sep
months[9]=Oct
months[10]=Nov
months[11]=Dec
timeFormat=$1
time=$2
command=$3
cdir=$(pwd)
cyear=$(date +%Y)
cmonth=$(date +%m)
cday=$(date +%d)
ddir=/tmp
if [ $command = "rm" ] 
then
	if [ $timeFormat = "-d" ]
	then
		rday=$(($cday-$time))
	elif [ $timeFormat = "-m" ]
	then
		rday=$(($cday-$(($time*30))))
	elif [ $timeFormat = "-y" ]
	then
		rday=$(($cday-$(($time*365))))
	fi
	rmonth=$(($cmonth-1))
	ryear=$cyear
	while [ $rday -lt 0 ]
	do
		rday=$(($rday+30))
		rmonth=$(($rmonth-1))
	done
	while [ $rmonth -lt 0 ]
	do
		rmonth=$(($rmonth+12))
		ryear=$(($ryear-1))
	done
	echo "Files created on and earlier than ${months[$rmonth]} $rday $ryear will be deleted. Do you want to continue?(y/n)"
	read input
	if [ $input != "y" ]
	then
		echo "Exiting."
		exit
	fi
elif [ $command = "cp" -o $command = "mv" ]
then
	echo "Where do you want the files? Type relative or exact path to the directory"
	while [ 1 -eq 1 ]
	do
		read inp
		if [ -d $inp ]
		then
			ddir=$inp
			break
		elif [ $inp = "-c" ]
		then
			exit
		else
			echo "No such directory. Type -c to cancel operation."
		fi
	done
else
	echo "Wrong command usage. Commands you can use: cp mv rm"
fi
for file in $cdir/*
	do
		if [ -d $file ]
		then
			continue
		fi
		filed=$(ls -la --time-style=+%Y\ %m\ %d $file|awk '{print $8}')
		filem=$(ls -la --time-style=+%Y\ %m\ %d $file|awk '{print $7}')
		filey=$(ls -la --time-style=+%Y\ %m\ %d $file|awk '{print $6}')
		yeardif=$(($cyear-$filey))
		monthdif=$(($cmonth-$filem))
		daydif=$(($cday-$filed))
		if [ $yeardif -ge 1 ]
		then
			ymonth=$(($yeardif*12))
			monthdif=$(($monthdif+$ymonth))
		fi
		if [ $monthdif -ge 1 ]
		then
			mday=$(($monthdif*30))
			daydif=$(($daydif+$mday))
		fi
		name=$(basename $file)
	case $timeFormat in

		-d ) 
			if [ $daydif -ge $time ]
			then
				if [ $command = "cp" -o $command = "mv" ]
				then
					$command $file "$ddir/$name"
				else
					$command $file
				fi
			fi
			;;

		-m )
			monthdif=$(($daydiff%30))
			if [ $monthdif -ge $time ]
			then
				if [ $command = "cp" -o $command = "mv" ]
				then
					$command $file "$ddir/$name"
				else
					$command $file
				fi
			fi
			;;
			
		-y )
			yeardif=$(($daydiff%365))
			if [ $yeardif -ge $time ]
			then
				if [ $command = "cp" -o $command = "mv" ]
				then
					$command $file "$ddir/$name"
				else
					$command $file
				fi
			fi
		
			;;
		* )
			echo "Wrong time-format. Formats you can use: -d(day) -m(month) -y(year)"
			exit
			;;
	esac 
done
echo "Successfull."
