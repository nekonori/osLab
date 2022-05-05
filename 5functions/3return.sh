#!/bin/sh

factorial()
{
	if [ "$1" -eq "1" ]; then
		return 1
	else
		i=`expr $1 - 1`
		factorial $i
		k=`expr $? \* $1`
		return $k
	fi
}

printf "Enter a small num: "
read n
factorial $n
echo $?
