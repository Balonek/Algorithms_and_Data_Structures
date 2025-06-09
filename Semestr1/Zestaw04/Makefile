CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
LDFLAGS = 

SOURCES = ArrayList.cpp CursorList.cpp
HEADERS = ArrayList.hpp CursorList.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = ArrayList.x CursorList.x

.PHONY: all clean tar

all: $(EXECUTABLES)

ArrayList.x: ArrayList.o
	$(CXX) $(LDFLAGS) -o $@ $^

CursorList.x: CursorList.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o $(EXECUTABLES)

tar:
	tar -czvf Zestaw04.tar.gz $(SOURCES) $(HEADERS) Makefile
