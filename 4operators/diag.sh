#!/bin/bash

input="./hello.txt"
string=""
count=0
while read line
do
	firstCharacter=${line:count:1}
	count=$((count+1))
	string="${string}${firstCharacter}"
done < "$input"

echo "String formed from diagonal characters is $string"
if [[ "$(echo "$string" | rev)" == "$string" ]]; then
	echo "String is a palindrome"
else
	echo "String is not a palindrome"
fi
