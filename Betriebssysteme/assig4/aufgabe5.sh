#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Nicht gut :( "
    exit 1
fi

if [ ! -d "$1" ] || [ ! -d "$2" ]; then
    echo "tre sa fie director"
    exit 1
fi

# mutam intregul director dir2 in directorul dir1
mv "$2" "$1/"

# vf daca mutarea a mers
if [ $? -eq 0 ]; then
    # iteram prin fisierele din directorul mutat
    for file in "$1/$2"/*; do
        if [ -f "$file" ]; then
            # numa fisier
            filename=$(basename -- "$file")
            filename="${filename%.*}"

            # redenumim fisierul si schimbam extensia in ".eins"
            mv "$file" "$1/$2/$filename.eins"
        fi
    done
    tree "$1"
else
    echo "Nu merge mutarea."
fi

