#pragma once
#include <stdexcept>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr);
};

class Stack {
private:
    Node* stk_top;
    int stk_size;

public:
    Stack();
    void push(int x);
    int pop();
    int size();
    bool empty();
};
