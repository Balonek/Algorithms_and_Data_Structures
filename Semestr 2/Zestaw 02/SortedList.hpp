#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>

template <class T>
class SortedList {

public:
    class Node {
    public:
        T value;
        Node* next;
        Node* prev;

        Node(T v) : value(v), next(nullptr), prev(nullptr) {}
    };

    SortedList() {
        sentinel = new Node(T());
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }

    ~SortedList() {
        clear();
        delete sentinel;
    }

    SortedList(const SortedList& other) : SortedList() {
        Node* current = other.sentinel->next;

        while (current != other.sentinel) {
            insert(current->value);
            current = current->next;
        }
    }

    SortedList& operator=(const SortedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.sentinel->next;
            while (current != other.sentinel) {
                insert(current->value);
                current = current->next;
            }
        }
        return *this;
    }

    void insert(const T& element) {
        Node* newNode = new Node(element);
        Node* current = sentinel->next;

        while (current != sentinel && current->value < element) {
            current = current->next;
        }

        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;

        size++;
    }

    void insertEnd(const T& element){
        Node* newNode = new Node(element);
        sentinel->prev->next = newNode;
        newNode->prev = sentinel->prev;
        newNode->next = sentinel;
        sentinel->prev = newNode;

        size++;
    }

    void remove(const T& element) {

        Node *current = sentinel;
        while (current->next != sentinel and current->next->value < element) {
            current = current->next;
        }
        if (current->next == sentinel or current->next->value > element) return;

        const Node *toDel = current->next;
        current->next = toDel->next;
        toDel->next->prev = current;
        delete toDel;
        size--;
    }

    bool contains(const T& element) {
        Node* current = sentinel->next;

        while (current != sentinel) {
            if (current->value == element) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        Node* current = sentinel->next;
        while (current != sentinel) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }

    bool equals(const SortedList<T>& other) const {
        if (this->size != other.size) {
            return false;
        }

        Node* thisCurrent = this->sentinel->next;
        Node* otherCurrent = other.sentinel->next;

        while (thisCurrent != this->sentinel) {
            if (thisCurrent->value != otherCurrent->value) {
                return false;
            }
            thisCurrent = thisCurrent->next;
            otherCurrent = otherCurrent->next;
        }

        return true;
    }

    struct Iterator {

        Iterator(Node* ptr) : m_ptr(ptr) {}

        T& operator*() const {
            return m_ptr->value;
        }

        T* operator->() {
            return m_ptr->value;
        }

        Iterator operator++() {
            m_ptr = m_ptr->next;
            return *this;
        }

        Node* GetNode () {
            return m_ptr;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        Node* m_ptr;
    };

    Iterator begin() {
        return Iterator(sentinel->next);
    }

    Iterator end() {
        return Iterator(sentinel);
    }

    void show() {
        Node *tmp = sentinel->next;
        while (tmp != sentinel) {
            std::cout << tmp->value << "  ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }


    bool operator==(const SortedList& other) const {
        return equals(other);
    }

    SortedList operator+(const SortedList& other) const {
        SortedList result(*this);
        Node* current = other.sentinel->next;
        while (current != other.sentinel) {
            result.insert(current->value);
            current = current->next;
        }
        return result;
    }

    SortedList operator-(const SortedList& other) const {
        SortedList result(*this);
        Node* current = other.sentinel->next;
        while (current != other.sentinel) {
            result.remove(current->value);
            current = current->next;
        }
        return result;
    }


private:
    Node* sentinel;
    int size;

};

#endif // SORTED_LIST_H