#!/bin/bash
#brew install coreutils


#ARG=($(gshuf -i 0-149 -n 20)) 

ARG="10 30 4 5 6 7 8" && ./push_swap $ARG > a && ./checker $ARG < a
echo " ${ARG[@]}\n"
wc -l a