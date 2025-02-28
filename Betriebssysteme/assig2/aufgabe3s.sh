#!/bin/bash


if [ $# -lt 2 ]; then
    echo "Argumente lipsa..."
    exit 1
fi


text=$1
shift


for file in "$@"; do
    if [ -r "$file" ]; then
	echo "-------------------------------------"
        echo "Fisier: $file"
        sed "1,30s/$text//g" "$file"
        echo "-------------------------------------"
    else
        echo "Fisierul $file nu exista..."
    fi
done

