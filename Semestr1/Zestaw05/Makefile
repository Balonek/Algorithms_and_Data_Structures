CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++20 -O2

EXECUTABLES := Generator.x bubblesort.x bubblesort_ccth.x insertionsort.x selectionsort.x

.PHONY: clean all

all: ${EXECUTABLES}

%.x: %.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm -f ${EXECUTABLES}