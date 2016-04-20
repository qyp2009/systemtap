#!/bin/bash

#cat tmp4.txt |sed '1d' |awk '{print $2,$3}' |sort -n -k1 -k2 |awk 'BEGIN {r1="";r2=""}  {if($1 == r1) {printf(" %s", $2);} else {r1=$1;printf("\n%s %s",$1,$2);}} END {print "";}'

if [[ $# < 1 ]] || [ ! -f "$1" ];then
	echo "eg: $0 input.txt";
	exit -1;
fi

cat $1 |
sed '1d' |
sort -n -k2 -k3 |
awk 'BEGIN {r2="";r3=""}  {if($2 == r2) {printf(" %s", $3);} else {r2=$2; printf("\n%s %s", $2, $3);}} END {print "";}'
