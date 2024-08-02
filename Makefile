CXX=g++
CXXFLAGS=-Wall -g -std=c++11
CLINK=$(CXX)

all: firewall.exe

firewal.exe: main.o libfirewall.so libinput.so
	$(CLINK) main.o -o firewall.exe -lfirewall -linput -L.

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

libfirewall.so: string.o ip.o port.o 
	$(CLINK) -shared string.o ip.o port.o -o libfirewall.so 

string-array.o: string-array.cpp string-array.h generic-string.h 
	$(CXX) $(CXXFLAGS) -c -fpic string-array.cpp 

string.o: string.cpp string.h generic-string.h string-array.o
	$(CXX) $(CXXFLAGS) -c -fpic string.cpp 

port.o: port.cpp port.h generic-field.h
	$(CXX) $(CXXFLAGS) -c -fpic port.cpp

ip.o: ip.cpp ip.h generic-field.h
	$(CXX) $(CXXFLAGS) -c -fpic ip.cpp

clean:
	rm -f *.o libfirewall.so