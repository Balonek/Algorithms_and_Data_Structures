#pragma once

class ArrayStack {
private:
    int top;
    int capacity;
    int* data;


public:
    ArrayStack(int capacity = 1000000);
    ~ArrayStack();
    void push(int x);
    int pop();
    int size();
    bool empty();
};