CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
LDFLAGS = 

SOURCES = Generator.cpp LinkedList.cpp
HEADERS = LinkedList.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = LinkedList.x Generator.x

.PHONY: all clean tar

all: $(EXECUTABLES)

LinkedList.x: LinkedList.o
	$(CXX) $(LDFLAGS) -o $@ $^

Generator.x: Generator.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o $(EXECUTABLES)

tar:
	tar -czvf Zestaw03.tar.gz $(SOURCES) $(HEADERS) Makefile
