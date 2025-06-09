CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++11

SOURCES = Dict.cpp 
HEADERS = Dict.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = Dict.x

.PHONY: all clean 

all: $(EXECUTABLES)

Dict.x: Dict.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o $(EXECUTABLES)

