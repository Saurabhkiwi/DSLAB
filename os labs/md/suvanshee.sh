#!/bin/sh
echo "enter a file name"
read fname
if [ -d "$fname"];then	
	echo "it is a directory"
elif [ -f "$fname" ];then
	echo "it is a  file"
else
	echo "invalid path"
fi 
