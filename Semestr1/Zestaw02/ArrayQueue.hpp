#pragma once

class Queue {
private:
    unsigned int head; 
    unsigned int tail;   
    unsigned int n;     
    int* data;           

public:
    Queue(unsigned int n); 
    ~Queue();

    void push(int x); 
    int pop(); 
    unsigned int size();
    bool empty(); 
};
