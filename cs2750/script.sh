#!/bin/bash

echo 'enter a number: \c'
read number 

if [ $number -lt 0 ] 
then 
	echo negative
elif [  $number -eq 0 ]
then 
	echo zero
else 
	echo positive 
fi
