t=0
while [ $t -lt 100 ]
do
	let "t=$t+1"
	echo $RANDOM|./gen>t.in
	./tmp<t.in>tmp.out
	./51nod_c<t.in>t.out
	if diff tmp.out t.out; then
		echo "AC $t";
	else 
		echo "WA $t";
		break;
	fi
done