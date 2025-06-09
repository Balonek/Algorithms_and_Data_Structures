CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17
LDFLAGS = 

SOURCES = ArrayQueue.cpp LinkedQueue.cpp Generator.cpp Queue.cpp Radix.cpp
HEADERS = ArrayQueue.hpp LinkedQueue.hpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = Generator.x Queue.x Radix.x

.PHONY: all clean tar

all: $(EXECUTABLES)

Queue.x: ArrayQueue.o Queue.o
	$(CXX) $(LDFLAGS) -o $@ $^

Generator.x: Generator.o
	$(CXX) $(LDFLAGS) -o $@ $^

Radix.x: Radix.o LinkedQueue.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o $(EXECUTABLES)

tar:
	tar -czvf Zestaw02.tar.gz $(SOURCES) $(HEADERS) Makefile
