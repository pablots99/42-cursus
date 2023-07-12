# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 20:09:53 by ptorres           #+#    #+#              #
#    Updated: 2023/03/20 19:49:43 by ptorres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
CONTAINER_HPP="../containers"

#brew install gdate

FAGS="-Wall -Wextra -Werror -g3 -std=c++98 -pedantic -pedantic-errors"
if [[ $1 == "--leaks" ]] || [[ $1 == "-leaks" ]]; then
    test=$2
    leaks="true"
else
    leaks="false"
    test=$1
fi 
mkdir results/ > /dev/null 2>&1


check_leaks() { 
    mkdir results/leaks > /dev/null 2>&1
    filename="results/leaks/$2_$1_leaks"
    status=✅
    valgrind --leak-check=full --track-origins=yes --error-exitcode=1 ./$1 > $filename 2>&1
    if [[ $? == 1 ]]; then
        status=🚨
    else
        rm $filename
    fi
    echo "***************************************"
    echo "Leaks $filename, satatus: $status"
    echo "***************************************"
}

execute_test() { 
    files=$(ls $1 | sed s/*util*.*//g)
    mkdir results/$1 > /dev/null 2>&1
    echo $1
    echo "------------------------------------------------------------------------------------------------------------"
    printf "%-20s| %-12s| %-12s| %-12s| %-18s| %-18s|\n" "name" "ft_compilation" "std_compilation" "diff_result" "ft_time" "std_time"
    for file in $files 
    do
        echo "------------------------------------------------------------------------------------------------------------"
        name=$(basename $file .cpp)

        ft_time=""
        ft_diff=""
        diff_result=""
        ft_copile_error=""
        std_copile_error=""
        
        start=$(python -c 'from time import time; print int(round(time() * 1000))')
        #test std
        clang++ $1/$file -o $name $FAGS -I  $CONTAINER_HPP -D LIBRARY=std > results/$1/std_$name 2>&1
        compile=$(cat results/$1/std_$name)
        if [[ -z $compile ]]; then
            ./$name 2>&1 >> results/$1/std_$name   #compile
            end=$(python -c 'from time import time; print int(round(time() * 1000))')
            std_time=$( echo "($end - $start) / 1000" | bc -l )
            if [[ $leaks == "true" ]]; then
                check_leaks $name "std"
            fi
            rm $name
        else
             std_copile_error="true"
        fi

        start=$(python -c 'from time import time; print int(round(time() * 1000))')
        #test ft
        clang++ $1/$file -o $name $FAGS -D LIBRARY=ft -I $CONTAINER_HPP > results/$1/ft_$name 2>&1   #compile
        compile=$(cat results/$1/ft_$name)
        if [[ -z $compile ]]; then
            ./$name 2>&1 >> results/$1/ft_$name
            end=$(python -c 'from time import time; print int(round(time() * 1000))')
            ft_time=$( echo "($end - $start) / 1000" | bc -l )
            if [[ $leaks == "true" ]]; then
                check_leaks $name "ft"
            fi
        else
             ft_copile_error="true"
        fi
        #diff
        diff -U 1000000 results/$1/std_$name results/$1/ft_$name > results/$1/diff_$name.diff
        diff_result=$(cat results/$1/diff_$name.diff)
        if [[ ! -z $diff_result ]]; then
            diff_result=🚨
        else
            rm results/$1/diff_$name.diff
            diff_result=✅
            rm $name
        fi
        if [[ $ft_copile_error == "true" ]]; then
            ft_copile_error=🚨
        else
            ft_copile_error=✅
            rm results/$1/ft_$name
        fi
        if [[ $std_copile_error == "true" ]]; then
            std_copile_error=🚨
        else
            rm results/$1/std_$name
            std_copile_error=✅
        fi
        
        #print results
        printf "%-20s| %-16s| %-17s| %-13s| %-18s| %-18s|\n" "$name" "$ft_copile_error" "$std_copile_error" "$diff_result" "$ft_time" "$std_time"
        #clean
        rm -rf *.dSYM
    done
}


if [[ "$test" == "vector" ]] || [[ -z "$test" ]]
then
    execute_test "vector"
fi

if [[ "$test" == "map" ]] || [[ -z "$test" ]]
then
    execute_test "map"
fi

if [[ "$test" == "stack" ]] || [[ -z "$test" ]]
then
    execute_test "stack"
fi
