#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdexcept>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
    Node() : data(0), next(this), prev(this) {}
};

class List {
public:
    List() : guard(new Node()), listSize(0) {}

    ~List() {
        clear();
        delete guard;
    }

    void push_front(int x) {
        Node* newNode = new Node(x);
        newNode->next = guard->next;
        newNode->prev = guard;
        guard->next->prev = newNode;
        guard->next = newNode;
        listSize++;
    }

    int pop_front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = guard->next;
        int data = temp->data;
        guard->next = temp->next;
        temp->next->prev = guard;
        delete temp;
        listSize--;
        return data;
    }

    void push_back(int x) {
        Node* newNode = new Node(x);
        newNode->next = guard;
        newNode->prev = guard->prev;
        guard->prev->next = newNode;
        guard->prev = newNode;
        listSize++;
    }

    int pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = guard->prev;
        int data = temp->data;
        guard->prev = temp->prev;
        temp->prev->next = guard;
        delete temp;
        listSize--;
        return data;
    }

    int size() const {
        return listSize;
    }

    bool empty() const {
        return listSize == 0;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    int find(int x) const {
        Node* current = guard->next;
        int pos = 0;
        while (current != guard) {
            if (current->data == x) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }

    int erase(int i) {
        if (i < 0 || i >= listSize) {
            throw std::out_of_range("Index is out of range");
        }
        Node* current = guard->next;
        for (int pos = 0; pos < i; ++pos) {
            current = current->next;
        }
        int data = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        listSize--;
        return data;
    }

    void insert(int i, int x) {
        if (i < 0 || i > listSize) {
            throw std::out_of_range("Index is out of range");
        }
        Node* current = guard;
        for (int p = 0; p < i; ++p) {
            current = current->next;
        }
        Node* newNode = new Node(x);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        listSize++;
    }

    int remove(int x) {
        int count = 0;
        Node* current = guard->next;
        while (current != guard) {
            if (current->data == x) {
                Node* temp = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = current->next;
                delete temp;
                count++;
                listSize--;
            } else {
                current = current->next;
            }
        }
        return count;
    }

private:
    Node* guard;
    int listSize;
};

#endif
