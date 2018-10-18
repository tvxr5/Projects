#!/bin/bash

num1 = $1
num2 = $2

sum = $1 + $2

echo "$1 + $2 = $sum"

if (($sum % 2 == 0))
	echo "This is even"
else
	echo "This is odd" 
