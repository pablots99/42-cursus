#!/bin/bash
#brew install coreutils

make > /dev/null
random=$((5 + $RANDOM % 30)) 
ARG=$(gshuf -i 0-$random -n ${random- 3}) 
echo "${ARG[@]}" > list

./push_swap $ARG > a
cat a

#./checker $ARG
res=$(wc -l a)
list=$(wc -l list)
echo "\n\nLen of the list: $list\nNumer of operations: $res"
