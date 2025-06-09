#pragma once
#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>

template<class T>
class LinkedList { 
private:
struct Node { 

    Node() : x{}, prev(nullptr), next(nullptr) {}
    Node(const T &e): x{e}, prev(nullptr), next(nullptr) {}

    T x; 
    Node* prev; 
    Node* next;
};
struct Iterator {
    Node *ptr;
    Iterator(Node *p = nullptr): ptr(p) {}

    Iterator operator++() {
        ptr = ptr->next;
        return *this;
    }
    Iterator operator++(int) {
        Node *temp = ptr;
        ptr = ptr->next;
        return Iterator(temp);
    }

    Iterator operator--() {
        ptr = ptr->prev;
        return *this;
    }
    Iterator operator--(int){
        Node *temp = ptr;
        ptr = ptr->prev;
        return Iterator{temp};
    }
    T& operator*(){
        return ptr->x;
    }
    T *operator->() { 
        return &(ptr->x);
    }
    bool operator==(const Iterator& other) const {
        return this->ptr == other.ptr;
    }
    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }
};
    Node guard;
    int lsize;
    int maxSize;
public:
    LinkedList(): lsize(0), maxSize(1000) {
        guard.next = &guard;
        guard.prev = &guard;
    }
    ~LinkedList() {
        clear(); 
    }

    template<class U> 
    void push_front(U&& x) {
        if (lsize == maxSize)
            throw std::out_of_range("Overflow");
        insert(begin(), std::forward<U>(x));
        /*std::forward jest używane w funkcjach szablonowych, które przekazują swoje argumenty 
        do innych funkcji, a te argumenty mogą być zarówno lvalue, jak i rvalue. 
        Chcemy przekazać argumenty do innej funkcji w taki sposób, aby zachować ich pierwotny typ.*/  
    }
    T pop_front() {
        if (lsize == 0) {
            throw std::out_of_range("EMPTY");
        }
        T val = guard.next->x;
        erase(Iterator{guard.next});
        return val;
    } 
    
    template<class U>
    void push_back(U&& x) {
        if (lsize == maxSize)
            throw std::out_of_range("Overflow");
        insert(end(), std::forward<U>(x));
    }
    T pop_back() {
        if (lsize == 0)
            throw std::out_of_range("EMPTY");
        T val = guard.prev->x;
        erase(Iterator{guard.prev});
        return val;
    } 
    Iterator find(const T& x) {
    for (auto it = begin(); it != end(); ++it) {
        if (*it == x) {
            return it;
        }
    }
    return end();
}

    Iterator erase(Iterator it) {
    if (it.ptr == &guard || empty() ) { 
        throw std::out_of_range("EMPTY");
    }
    --lsize; 
    Iterator toreturn = Iterator{it.ptr->next};
    it.ptr->prev->next = it.ptr->next;
    it.ptr->next->prev = it.ptr->prev;

    delete it.ptr;
    return toreturn;
}
    template<class U>
    bool replace(const T& x, U&& y)
    {
        Iterator index = find(x);
        if(index != end())
        {
            insert(erase(index), std::forward<U>(y));
            return true;
        }
        return false;
    }
    template<class U>
    Iterator insert(Iterator it, U&& x) {
        if (lsize >= maxSize) {
            throw std::out_of_range("Overflow");
        }
        lsize++;
        Node *n = new Node(std::forward<U>(x));
        if(lsize == 1)
        {
            guard.next = n;
            guard.prev = n;
            n->next = &guard;
            n->prev = &guard;
            return Iterator{n}; 
        }
        n->next = it.ptr;
        n->prev = it.ptr->prev;
        it.ptr->prev = n;
        n->prev->next = n;
        return Iterator{n};
    }

    int remove(const T& x) {
        int count = 0;    
        for (auto it = begin(); it != end(); it++) {
            if(*it == x) {
                count++;
                it = erase(it);
            }
        return count;
    } }
    int size() const {
        return lsize;
    }
    bool empty() {
        return size() == 0;
    }
    void clear() {
        while (!empty()) {
            erase(begin());
        }
    }
    Iterator begin() {
        return Iterator(guard.next);
    } 
    Iterator end() {
        return Iterator(&guard);
    } 
};