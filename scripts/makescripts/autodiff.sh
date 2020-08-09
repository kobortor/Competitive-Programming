#!/bin/bash

mkdir -p data;
for input in data/*.in; do 
    id=$(echo "$input" | sed "s/data\\/\(.*\)\.in/\1/g")
    printf "Running sample input $id: "
    tmp=$(echo $input | sed 's/in/tmp/g')
    output="data/$id.out" 
    timeout 3s ./a.out < "$input" > "$tmp"
    code="$?"
    if [[ "$code" -eq 124 ]]; then	
        printf "\\033[0;33mTLE\\033[0m!\n\n"
        continue 
    elif [[ $code -ne 0 ]]; then
        printf "\\033[0;33mRTE $code\\033[0m!\n\n"
        continue
    fi
    if diff -b $tmp $output > /dev/null
    then printf "\\033[0;32mAC\\033[0m"
    else
        printf "\\033[0;31mWA\\033[0m\n"
        icdiff $tmp $output
    fi
    echo
done
