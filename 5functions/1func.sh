#!/bin/sh

create_file()
{
	echo "Enter file name"
	read FILE_NAME;
	mkdir "files"
	touch "files/$FILE_NAME"
	echo "File created successfully in files dir!"
}

create_file
