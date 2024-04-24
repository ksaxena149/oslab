echo "Enter a positive integer";
read num;
if [ $num -lt 0 ]
then
	echo "Please provide a positive integer";
	exit 1;
fi

factorial=1;
for (( i=1; i<=num; i++ ))
do
	factorial=$((factorial * i))
done

echo "The factorial of $num is $factorial."
