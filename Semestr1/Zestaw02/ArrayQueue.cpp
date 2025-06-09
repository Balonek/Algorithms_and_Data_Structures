#include "ArrayQueue.hpp"
#include <stdexcept>
#include <iostream>

Queue::Queue(unsigned int n) : head(0), tail(0), n(n+1) {
    if (n <= 0) {
        throw std::invalid_argument("Rozmiar kolejki musi być większy od 0");
    }  
    data = new int[n+1];  
}

Queue::~Queue() {
    delete[] data;  
}

void Queue::push(int x) {
    if (size() == n) {
        throw std::out_of_range("Queue overflow");
    }
    data[tail] = x;
    tail = (tail + 1) % n; 
}
int Queue::pop() {
    if (empty()) {
        throw std::out_of_range("EMPTY");
    }
    int value = data[head];
    head = (head + 1) % n; 
    return value;
}

unsigned int Queue::size() {
    return (tail + n - head) % n;
}

bool Queue::empty() {
    return size() == 0;
}
