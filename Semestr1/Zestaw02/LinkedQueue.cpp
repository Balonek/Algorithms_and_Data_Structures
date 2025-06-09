#include "LinkedQueue.hpp"
#include <iostream>

Node::Node(int value, Node* next) : data(value), next(next) {}

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (!empty()) {
        pop();
    }
}

void Queue::push(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int Queue::pop() {
    if (head == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    return value;
}

int Queue::size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

bool Queue::empty() {
    return head == nullptr;
}
