


make > /dev/null 2>&1
if [[ $? -ne 0 ]]; then
	echo "Error compiling pipex";
	exit 1;
fi


touch infile
touch outfile
touch outfile1

total=0
acertadas=0
#test1
echo "TEST1"
echo "CMD: <infile ls -la | wc -l > outfile"
<infile ls -la | wc -l > outfile
sleep 0.5
./pipex infile "ls -la" "wc -l" outfile1
sleep 0.5

diff outfile outfile1
if [[ $? -ne 0 ]]; then
	echo "KO"
else
	acertadas=$(( $acertadas + 1 ))
	echo "OK"
fi
	total=$(( $total + 1 ))

#test2
echo "TEST2"
echo "CMD: <infile grep a1 | wc -w >outfile"
<infile grep a1 | wc -w >outfile
sleep 0.5
./pipex infile "grep a1" "wc -w" outfile1
sleep 0.5
diff outfile outfile1
if [[ $? -ne 0 ]]; then
	echo "KO"
else
	acertadas=$(( $acertadas + 1 ))
	echo "OK"
fi
	total=$(( $total + 1 ))

#test3
echo "TEST3"
echo "CMD: <infile ls -l | grep pipex >outfile"
<infile ls -l | grep pipex >outfile
sleep 0.5
./pipex infile "ls -l" "grep pipex" outfile1
sleep 0.5
diff outfile outfile1
if [[ $? -ne 0 ]]; then
	echo "KO"
else
	acertadas=$(( $acertadas + 1 ))
	echo "OK"
fi
	total=$(( $total + 1 ))

#test4
echo "TEST4"
echo "CMD: <infile ls -l | sed -e s/[aeio]/u/g  >outfile"
<infile ls -l | sed -e "s/[aeio]/u/g"  >outfile
sleep 0.5
./pipex infile "ls -l" 'sed -e s/[aeio]/u/g' outfile1
sleep 0.5
diff outfile outfile1
if [[ $? -ne 0 ]]; then
	echo "KO"
else
	acertadas=$(( $acertadas + 1 ))
	echo "OK"
fi
total=$(( $total + 1 ))
#test5
echo "TEST5"
echo "CMD: <infile ls -l | sed -e s/[aeio]/u/g  >outfile"
<infile ls -l | sed -e s/[aeio]/u/g  >outfile
sleep 0.5
./pipex infile "ls -l" 'sed -e s/[aeio]/u/g' outfile1
sleep 0.5
diff outfile outfile1
if [[ $? -ne 0 ]]; then
	echo "KO"
else
	acertadas=$(( $acertadas + 1 ))
	echo "OK"
fi
total=$(( $total + 1 ))

#bonus
if [[ -n "$1" && "$1" == "bonus" ]]; then
	echo "BONUS"
else

	echo $acertadas"/"$total
	exit 0;
fi

#testbonus1
echo "BONUS1"
echo "CMD: <infile ls -l | sed -e s/[aeio]/u/g  >outfile"
<infile ls -l | sed -e s/[aeio]/u/g  >outfile
sleep 0.5
./pipex infile "ls -l" 'sed -e s/[aeio]/u/g' outfile1
sleep 0.5
diff outfile outfile1
if [[ $? -ne 0 ]]; then
	echo "KO"
else
	acertadas=$(( $acertadas + 1 ))
	echo "OK"
fi
total=$(( $total + 1 ))
