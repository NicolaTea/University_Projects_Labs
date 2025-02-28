#!/bin/bash


if [ $# -ne 1 ]; then
    echo "Argumente lipsa..."
    exit 1
fi


directory=$1


if [ ! -d "$directory" ]; then
    echo "Directorul '$directory' nu exista."
    exit 1
fi


echo "Numele fisierelor ASCII din directorul '$directory' (sortate):"
for file in "$directory"/*; do
    if [ -f "$file" ] && file "$file" | grep -q  "text"; then
        echo "$(basename "$file")"
    fi
done | sort




