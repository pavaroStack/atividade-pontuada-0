.cpp.o:	$*.h
	g++	-c $*.cpp

all:	testSort

testSort:  testSort.o sortAlgs.o
	g++ -o $@ $^

clean:
	rm testSort *.o
