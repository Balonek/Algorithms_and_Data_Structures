CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17
LDFLAGS = 

SOURCES = ArrayStack.cpp LinkedStack.cpp Stack.cpp Generator.cpp ONP.cpp
HEADERS = ArrayStack.hpp LinkedStack.hpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = Stack.x Generator.x ONP.x

.PHONY: all clean tar

all: $(EXECUTABLES)

Stack.x: ArrayStack.o LinkedStack.o Stack.o
	$(CXX) $(LDFLAGS) -o $@ $^

Generator.x: Generator.o
	$(CXX) $(LDFLAGS) -o $@ $^

ONP.x: ONP.o ArrayStack.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o $(EXECUTABLES)

tar:
	tar -czvf Zestaw01.tar.gz $(SOURCES) $(HEADERS) Makefile
