echo "Enter first number";
read num1;
echo "Enter second number";
read num2;

add=`expr $num1 + $num2`;
sub=`expr $num1 - $num2`;
mul=`expr $num1 \* $num2`;

if [ $num2 -ne 0 ]
then
	div=`expr $num1 / $num2`;
else
	div="Not Defined";
fi

echo "Addition: $add";
echo "Subtraction: $sub";
echo "Multiplication: $mul";
echo "Division: $div";
