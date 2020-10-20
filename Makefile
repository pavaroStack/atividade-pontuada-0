.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	testSort 

testSort:	testSort.o sorting.o
	g++ -o $@ $^


clean:
	rm *.o TADExample 
	