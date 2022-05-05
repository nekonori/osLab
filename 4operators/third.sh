#!/bin/bash

getNoOfDigits () {
	num=$1
	num=$(($num+1))
	ans=0
	while [ $num -gt 0 ]
	do
		ans=$(($ans+1))
		num=$(($num/10))
	done
	return $ans;
}

isArmstrong () {
	n=$1
	getNoOfDigits $1
	digits=$?
	nsum=0
	while [ $n -gt 0 ]
	do
		cur=$((($n%10)**$digits))
		n=$(($n/10))
		nsum=$(($nsum+$cur))
	done
	if [ $nsum == $1 ]; then
		return 1
	fi
	return 0
}

numString=$(grep -Eo '[0-9]+' hel1.txt)
string=""
while read line
do
  string+="${line}"
done <<< "$numString"

echo "Number is $string"

isArmstrong $string
ans=$?
if [ $ans -eq 1  ]; then
	echo "Armstrong number"
else
	echo "Not a armstrong number"
fi
