#!/bin/sh

read -p "enter the directory path : " directory
read -p "enter the pattern : " pattern 
ls $directory | grep "$pattern"
