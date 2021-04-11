#!/bin/bash
#brew install coreutils

make re > /dev/null
random=$((5 + $RANDOM % 30)) 
ARG=($(gshuf -i 0-$random -n $random )) 
echo "list: ${ARG[@]}\n\n"

./push_swap $ARG > a
cat a
#./checker $ARG < a
res=$(wc -l a)
echo "\n\nLen of the list: ${#ARG[@]}\nNumer of operations: $res"
