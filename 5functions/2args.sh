#!/bin/sh

calcAge()
{
	DOB=$1
	d=${DOB:0:2}
	m=${DOB:3:2}
	y=${DOB:6:4}
	today=$(date -Idate)
	ty=${today:0:4}
	tm=${today:5:2}
	td=${today:8:2}
	dd=$(expr $td - $d)
	md=$(expr $tm - $m)
	ans=$(expr $ty - $y)
	if [ $dd -gt 0 ] && [ $md -gt 0 ]; then
	ans=$((ans+1))
	fi
	echo "Your age is $ans"
}

echo "Enter your dob (dd-mm-yyyy)"
read DOB

calcAge $DOB
