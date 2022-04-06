x=1
time=0.2
BINPATH=./philosophers
echo "1 400 100 100 should die\n"
while [ $x -le 2 ]
do
	echo "Test: $x"
	$BINPATH 1 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n2 150 360 100 25 should die"
echo "2 100 200 200 25 should die"
echo "2 150 200 100 25 should die\n"
while [ $x -le 2 ]
do
	echo "Test: $x"
	$BINPATH 2 150 360 100 25 | grep die
	$BINPATH 2 100 200 200 25 | grep die
	$BINPATH 2 150 200 100 25 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n4 210 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	$BINPATH 4 210 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n4 310 200 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	$BINPATH 4 310 200 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n5 400 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	$BINPATH 5 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n5 150 100 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	$BINPATH 5 150 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n3 400 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	$BINPATH 3 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.2
echo "\n3 150 100 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	$BINPATH 3 150 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done