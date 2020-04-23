FOLDER="$(pwd)/src/include/"
for i in $(ls tests | grep "_test.c")
do
	$(cc -g -Wall -O3 -I$FOLDER tests/$i -o all_tests)
done
