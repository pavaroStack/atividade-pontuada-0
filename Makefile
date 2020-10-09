.cpp.o:	$*.h
	g++	-c $*.cpp

all:	testSort

testSort:  testSort.cpp 
	g++ $@ $^ && ./testSort

clean:
	rm testSort *.o
