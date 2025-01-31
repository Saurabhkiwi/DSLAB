#!/bin/sh
read -p "enter basics : " basics
read -p "enter TA: " TA
GS=$(echo "($basics + $TA + $basics * 0.1)" | bc)
echo "GS = $GS"
