./philo 3 810 200 200 5 | grep "is eating" | awk '{print $2}' | sort | uniq -c
