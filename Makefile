CXX=g++
CXXFLAGS= -Wall -g -std=c++11
LDFLAGS= -pthread
all: grabber
grabber: grabber.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@  $< 

.PHONY: clean run
clean:
	rm grabber

run: grabber
	 nice -n 20 ./grabber
