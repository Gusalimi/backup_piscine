#!/bin/sh
cat /etc/passwd | grep -E '^#' -v | sed 's/:.*//' | sed g\;n | sed '/^$/d' | rev | sort -r | tr -d " " | head -n $FT_LINE2 | tail -n $(($FT_LINE2-$FT_LINE1+1)) | tr "\n" "," | sed "s/,$/./" | sed "s/,/, /g" | tr -d '\n'
