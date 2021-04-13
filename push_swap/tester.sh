#!/bin/bash
#brew install coreutils
make > /dev/null

Black='\033[0;30m'        
Red='\033[0;31m'         
Green='\033[0;32m'      
Yellow='\033[0;33m'    
Blue='\033[0;34m'     
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[0;37m'
endColour='\033[0m'

if [ -z "$1" ] || [ -z "$2" ] || [ -n "$3" ]
then
	echo "${Red}error: the script need 2 arguments$endColour"
	exit 1
fi
re='^[0-9]+$'
if ! [[ $1 =~ $re ]] ; then
   echo "${Red}error: Argument 1 not a number $endColour" >&2; exit 1
fi
re='^[0-9]+$'
if ! [[ $2 =~ $re ]] ; then
   echo "${Red}error: Argument 2 not a number $endColour" >&2; exit 1
fi

error=0
final[0]=""
for i in $(seq 0 $2);
do
	ARG=$(gshuf -i 0-$1 -n $1) 
	echo "${ARG[@]}" > list
	./push_swap $ARG > a
	checker=$(./checker $ARG < a)
	aux="[OK]"
	if [[ "$checker" != "$aux" ]]
	then	
		echo "${Red}NOT WORKIIIING !!! test_numner: $i: checker: $checker $endColour"
		break 
	fi
	res=$(wc -l a)
	res=${res%??}
	res="${res//[[:blank:]]/}"
	final[i]=$res
done

if [[ -n "$error" ]]
then
	exit 
fi
nums=${ARG[@]}
min=${final[0]}
max=${final[0]}
media=0
for i in ${final[*]};
do
	if [[ "$min" -gt "$i" ]]
	then 
		min=$i
	fi
	if [[ "$max" -lt "$i" ]]
	then 
		max=$i
	fi
	media=$((media+$i))
done
echo "${Purple}Length of the list:${endColour}${Blue} $1 $endColour"
echo "${Purple}Max movements:${endColour}${Blue} $max ${endColour}"
echo "${Purple}Min movements:${endColour}${Blue} $min $endColour"
echo "${Purple}Total movements:${endColour}${Blue} $media $endColour"
media=$(( $media / $2 )) 
echo "${Purple}Media movents:${endColour}${Blue} $media $endColou"





rm -rf checker.dSYM