#pragma once
#include <stdexcept>

struct Node {
    int data;
    Node* next;
    Node(int value, Node* next = nullptr);
};
    
class Queue {
private:
    Node* head; 
    Node* tail; 

public:
    Queue(); 
    ~Queue();
    void push(int x); 
    int pop(); 
    int size();
    bool empty();
};