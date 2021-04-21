#!/bin/bash
#brew install coreutils
make re > /dev/null

Black='\033[0;30m'        
Red='\033[0;31m'         
Green='\033[0;32m'      
Yellow='\033[0;33m'    
Blue='\033[0;34m'     
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[0;37m'
endColour='\033[0m'

if [[ "$1" == "-h" ]] || [[ "$1" == "-help" ]] || [[ "$1" == "--help" ]] || [[ "$1" == "help" ]]
then
		echo "${Yellow}help: the script need 2 arguments$endColour \n${Cyan}      1->for the len of the list of numbers.\n      2->times is going to execute the program.$endColour\n${Yellow}help: the script has to be in the root of push_swap$endColour"; exit 1
fi

if [ -z "$1" ] || [ -z "$2" ] || [ -n "$3" ] 
then
	echo "${Red}error: the script need 2 arguments$endColour \n${Cyan}      1->for the len of the list of numbers.\n      2->times is going to execute the program."; exit 1
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
	printf "${Yellow}Loading:$i/$2\r$endColour"
	start=$((0))
	end=$(($1))
	ARG=$(gshuf -i $start-$end -n $1) 
	echo "${ARG[@]}" > list
	./push_swap $ARG > a
	checker=$(./checker $ARG < a)
	aux="[OK]"
	if [[ "$checker" != "$aux" ]]
	then	
		error=1
		echo -e "\r${Red}error:BAD ALGORITHM RESULT!!! test_numner: $i: checker: $checker $endColour"; break 
	fi
	res=$(wc -l a)
	res=${res%??}
	res="${res//[[:blank:]]/}"
	final[i]=$res
done

if [[ $error == "1" ]]
then
	exit 1;
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
echo "\b${Green}Results${endColour}"
echo "${Purple}Length of the list:${endColour}${Blue} $1 $endColour"
echo "${Purple}Max movements:${endColour}${Blue} $max ${endColour}"
echo "${Purple}Min movements:${endColour}${Blue} $min $endColour"
echo "${Purple}Total movements:${endColour}${Blue} $media $endColour"
media=$(( $media / ($2+1) )) 
echo "${Purple}Media movents:${endColour}${Blue} $media $endColou"

rm -rf checker.dSYM