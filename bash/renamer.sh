#!/bin/bash

#UBICAR LA CARPETA
shopt -s extglob
FILES=$(ls *.gz)
NEW="$(date +"%Y-%m-%d")"
for FILE in !(ls *.gz); do
   if [ "${FILE##*.}" = "sh" ]; then
       echo "" # operation for txt files here
   else
    echo "Renaming" $FILE " -> to New name: "$NEW"-"$FILE
    mv "$FILE" "$NEW-$FILE"
   fi
done




