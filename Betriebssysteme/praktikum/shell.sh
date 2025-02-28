#!/bin/bash


if [ -z "$1" ]; then
    echo "nr argurmente"
    exit 1
fi


DIRECTOR="$1"


if [ ! -d "$DIRECTOR" ]; then
    echo "nu e director valid."
    exit 1
fi


find "$DIRECTOR" -type f -name '*.txt' | while read -r fisier; do
    echo "Fișier: $fisier"
    sort "$fisier" | uniq
    echo ""
done



