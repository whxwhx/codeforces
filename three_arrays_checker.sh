#!/bin/bash
t=0
while [ $t -lt 100 ]
do 
	let "t=$t+1"
	echo $RANDOM|./three_arrays_gen>3a.in
	./three_arrays<3a.in>3a.out
	./three_arrays_baoli<3a.in>3ab.out
	if diff 3a.out 3ab.out; then
		echo "AC $t";
	else
		echo "WA $t";
		break;
	fi
done