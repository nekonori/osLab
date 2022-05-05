# title: Shell programming basics

write aim, how to create shell files
echo statement, data types, if if else for, looping, comments mention fi
menu program, asterisk printing of your name



#!/bin/sh

### print statements
echo "Hello, World!"

echo What is your name?
read NAME
echo "Hello $NAME"

### getting input
echo "What's your name?"
read USER_NAME
echo "Hello $USER_NAME"
echo "Creating a new file called $USER_NAME.txt"
touch $USER_NAME.txt
echo "Done. Running ls..."
ls -l

### for loop
for i in 1 2 3 4 5
do
	echo Looping ... number $i
done

for i in hello 1 * 2 goodbye 
do
  echo "Looping ... i is set to $i"
done

### while loop
INPUT=hello

while [ $INPUT != "bye" ]
do
	echo "Enter something: (bye to quit)"
	read INPUT
	echo "Got: $INPUT"
done


### conditinoals
echo "Enter a number: "
read NUM
MAGIC_NUM=7
if [ $NUM -eq $MAGIC_NUM ]; then
	echo "You found the magic number"
elif [ $NUM -lt $MAGIC_NUM ]; then
	echo "Guess is less"
else
	echo "Guess is high"
fi

echo "Enter a number: "
read NUM
MAGIC_NUM=7
while [ $NUM != $MAGIC_NUM ]
do
	[ $NUM -lt $MAGIC_NUM ] && \
		echo "Guess is less"
	[ $NUM -gt $MAGIC_NUM ] && \
		echo "Guess is high"
	echo "Try again: "
	read NUM
done

[ $NUM -eq $MAGIC_NUM ] && \
	echo "You found the magic number!"


