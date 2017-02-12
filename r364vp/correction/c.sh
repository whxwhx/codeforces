t=0
while [ $t -lt 100000 ]
do
	let "t=$t+1"
	echo $RANDOM|./gen>t.in
	./force<t.in>f.out
	./e<t.in>t.out
	if diff f.out t.out; then
		echo "AC $t";
	else 
		echo "WA $t";
		break;
	fi
done