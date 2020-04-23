CFALGS=-g -Wall -O3 
CC=cc

all: test

clean:
	rm all_tests
test:
	./runtest.sh 

