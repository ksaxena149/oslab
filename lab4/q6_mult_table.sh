echo "Enter a number";
read a;

for(( i=1; i<=10; i++ ))
do
	mul=`expr $i \* $a`;
	echo "$a * $i = $mul";
done
