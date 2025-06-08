#ifndef DICTIONARYSIMPLE_H
#define DICTIONARYSIMPLE_H

#include <iostream>
#include <string>

#define N 1000

template <typename T>
class dictionarySimple {
public:
    dictionarySimple() : size(0) {}

    void insert(const T& element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return; 
            }
        }
        elements[size] = element;
        size++;
    }

    void remove(const T& element) {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                for (int j = i; j < size - 1; ++j) {
                    elements[j] = elements[j + 1];
                }
                size--;
                return;
            }
        }
    }

    bool contains(const T& element) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    void display() const {
        std::cout << "dictionarySimple elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << "\n";
    }

private:
    T elements[N];
    int size;
};

#endif
