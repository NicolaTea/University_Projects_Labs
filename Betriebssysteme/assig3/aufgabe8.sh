#!/bin/bash

if [ $# -ne 1 ]; then
    echo "nicht gut :("
    exit 1
fi

filename="$1"

awk '

BEGIN {
    total_sum = 0
    lines_with_numbers = 0
    lines_without_numbers = 0
}


{
    found_number = 0
    for (i = 1; i <= NF; i++) {
        if ($i ~ /^-?[0-9]+(\.[0-9]+)?$/) {
            total_sum += $i
            found_number = 1
        }
    }
    if(found_number){
	lines_with_numbers++
    }else{
	lines_without_numbers++
    }

}
END {
    print total_sum, lines_with_numbers ":" lines_without_numbers
}
' "$filename"



