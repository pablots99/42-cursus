
make > 2




echo "test1...."
./philo 3 800 200 200 10 > a
res=$(cat a | grep "is eating" | sort -n -k2)
echo $res
echo "test2"
echo "test3"
echo "test4"
echo "test5"