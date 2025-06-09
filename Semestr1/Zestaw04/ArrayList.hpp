#pragma once
#include <iostream>
#include <stdexcept>

class ArrayList {
    int* arr;
    int capacity;
    int current_size;

public:
    ArrayList(int max_capacity = 1000) : capacity(max_capacity), current_size(0) {
        arr = new int[capacity];
    }
    
    ~ArrayList() {
        delete[] arr;
    }

    void push_front(int x) {
        if (current_size >= capacity) {
            throw std::out_of_range("Overflow");
        }
        for (int i = current_size; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        ++current_size;
    }

    int pop_front() {
        if (empty()) {
            throw std::out_of_range("Underflow");
        }
        int value = arr[0];
        for (int i = 1; i < current_size; ++i) {
            arr[i - 1] = arr[i];
        }
        --current_size;
        return value;
    }

    void push_back(int x) {
        if (current_size >= capacity) {
            throw std::out_of_range("Overflow");
        }
        arr[current_size++] = x;
    }

    int pop_back() {
        if (empty()) {
            throw std::out_of_range("Underflow");
        }
        return arr[--current_size];
    }

    int size() const {
        return current_size;
    }

    bool empty() const {
        return current_size == 0;
    }

    void clear() {
        current_size = 0;
    }

    int find(int x) const {
        for (int i = 0; i < current_size; ++i) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int erase(int i) { // Usuwa i zwraca element na pozycji `i`
        if (i < 0 || i >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        int value = arr[i];
        for (int j = i; j < current_size - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        --current_size;
        return value;
    }

    void insert(int i, int x) { // Wstawia element `x` przed pozycję `i`
        if (i < 0 || i > current_size || current_size >= capacity) {
            throw std::out_of_range("Error");
        }
        for (int j = current_size - 1; j >= i; --j) {
            arr[j + 1] = arr[j];
        }
        arr[i] = x;
        ++current_size;

    }

    int remove(int x) { // Usuwa wystąpienia `x` i zwraca ich liczbę
        int count = 0;
        for (int i = 0; i < current_size;) {
            if (arr[i] == x) {
                erase(i);
                ++count;
            } else {
                ++i;
            }
        }
        return count;
    }
};