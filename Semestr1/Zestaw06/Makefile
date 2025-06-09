CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++11

SOURCES = BinaryTree.cpp 
HEADERS = BinaryTree.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = BinaryTree.x

.PHONY: all clean tar

all: $(EXECUTABLES)

BinaryTree.x: BinaryTree.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o $(EXECUTABLES)

tar:
	tar -czvf Zestaw06.tar.gz $(SOURCES) $(HEADERS) Makefile
