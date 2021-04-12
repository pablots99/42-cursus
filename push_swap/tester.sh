#!/bin/bash
#brew install coreutils

make > /dev/null

final=""
for i in {3..100}
do
	random=$((3 + $RANDOM % $i)) 
	ARG=$(gshuf -i 0-$random -n $i) 
	echo "${ARG[@]}" > list
	./push_swap $ARG > a
	checker=$(./checker $ARG < a)
	aux="[OK]"
	if [[ "$checker" != "$aux" ]]
	then	
		echo "$i: $checker"
		break 
	fi
	res=$(wc -l a)
	list=$(wc -l list)
	final+=("Len of the list: $list  Numer of operations: $res\n")
	#echo "\n\nLen of the list: $list\nNumer of operations: $res"
done
	echo "${final[@]}\n" > final