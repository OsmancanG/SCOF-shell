#!/bin/sh
clear
i=1
flg=1
while [ $i -eq 1 ]
do
	if [ $flg -eq 1 ]
	then
		echo "******************************************************************"
		temp=$(pwd)
		totalSize=0
		fName=$(basename $temp)
		echo "------------------------------------"
		echo "|$fName"
		if    ls -1qA $temp | grep -q .
		then
			for word in $temp/*
			do
				fileSize=$(du -sb $word | awk '{print $1}') 2>/dev/null 
				totalSize=$(($fileSize+$totalSize))
				if [ -d "$word" ]
				then
					echo "|	$(basename "$word:") d* $fileSize bytes"
				else
					echo "|	$(basename "$word:") $fileSize bytes"	
				fi
			done
		fi
		echo "|Total size: $totalSize bytes
------------------------------------
		
"
		echo "Type help to see functions."
		
	fi
	read input
	if [ -d $input ]
	then
			cd $input
			clear
			flg=1
	else
		case $input in 
		
			"help" )
				echo "Type a directory name to navigate,
Type .. to go up one directory,
Type filename to get file Info,
Type fcreate to create a new file,
Type dcreate to create new folder/directory,
Type exit to quit."
				flg=0
				;;
				
			"exit" )
				i=0
				;;
				
			".." )
				cd ..
				clear
				flg=1
				;;

			"fcreate")
				clear
				echo "Type the name of the file you want to create, ... to cancel."
				read input2
				if [$input2 = "..."]
				then
					echo "File creation cancelled."
					sleep 1
				else
					touch $input2
				fi
				clear
				flg=1
				;;
			
			"dcreate")
				clear
				echo "Type the name of the directory you want to create ... to cancel."
				read input2
				if [$input2 = "..."]
				then
					echo "Directory creation cancelled."
					sleep 1
				else
					mkdir $input2
				fi
				clear
				flg=1
				;;
			*.* )
				lines=$(wc -l $input | awk '{print $1}')
				words=$(wc -w $input | awk '{print $1}')
				chars=$(wc -m $input | awk '{print $1}')
				echo "$input has $lines lines, $words words and $chars chars"
				flg=0
				;;
			
			* )
				echo "Wrong input, type help to see commands"
				flg=0
				;;
		esac
	fi
done
echo "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



"
sleep 3
clear
