# Makefile for Lab04a Sai KAthika

CXX = g++

# main: WordCount.o
# 	${CXX} -o main WordCount.o

test: test2.o tddFuncs.o WordCount.o
	${CXX} $^ -o $@

tests: test
	./test

clean :
	rm -f *.o test
