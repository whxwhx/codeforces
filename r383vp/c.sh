t=0
while [ $t -lt 10000 ]
do
	let "t=$t+1"
	echo $RANDOM|./gen>f2.in
	./d<f2.in>t.out
	./f2<f2.in>f.out
	if diff t.out f.out; then 
		echo "AC $t";
	else
		echo "WA $t";
		break;
	fi
done