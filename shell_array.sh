#!/bin/bash

str="0 1 2 3 4 5 6 7 8 9"
arr=($str)

sub_sum=0;

for ((i=2;i<${#arr[@]};i+=2))
do
	echo ${arr[i]},${arr[i+1]};
	sub_sum=$(($sub_sum+$((${arr[i+1]}-${arr[i]}))));
done

echo $sub_sum;
