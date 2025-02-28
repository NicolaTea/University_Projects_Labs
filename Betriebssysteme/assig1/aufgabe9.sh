#!/bin/bash
a=$1
b=$2
c=$3
e=$4
f=$5
g=$6


produkt=$((a*e + b*f + c*g))

if [ $produkt -eq 0 ]
   then
    echo "ja"
else
    echo "nein"
fi
