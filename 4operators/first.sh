#!/bin/bash

input="./hello.txt"
string=""
while read line
do
  firstCharacter=${line:0:1}
  string="${string}${firstCharacter}"
done < "$input"

echo "String formed from first characters is $string"
if [[ "$(echo "$string" | rev)" == "$string" ]]; then
	echo "String is a palindrome"
fi
