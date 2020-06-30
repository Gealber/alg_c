#!/bin/bash

FOLDER="$(pwd)/src/include/"
for i in $(ls tests | grep "_test.c")
do
	tmp_test="${i/.c/}"
	$(cc -g -Wall -O3 -I$FOLDER tests/$i -o $tmp_test)
	#./$tmp_test
	#rm $tmp_test
done
