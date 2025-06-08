#ifndef SET_LINKED_H
#define SET_LINKED_H

#include <iostream>

template<class T>
class setLinked {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val): value(val), next(nullptr){}
    };
    Node* head;

public:
    setLinked() : head(nullptr) {}

    setLinked<T> sum_of_sets(const setLinked<T>& setB) const {
        setLinked<T> result;
        Node* current = head;
        Node* currentB = setB.head;
        while (current != nullptr || currentB != nullptr) {
            if (current == nullptr) {
                result.insert(currentB->value);
                currentB = currentB->next;
            } else if (currentB == nullptr) {
                result.insert(current->value);
                current = current->next;
            } else if (current->value < currentB->value) {
                result.insert(current->value);
                current = current->next;
            } else if (current->value > currentB->value) {
                result.insert(currentB->value);
                currentB = currentB->next;
            } else {
                result.insert(current->value);
                current = current->next;
                currentB = currentB->next;
            }
        }
        return result;
    }

    setLinked<T> intersection_of_sets(const setLinked<T>& setB) const {
        setLinked<T> result;
        Node* currentA = head;
        Node* currentB = setB.head;
        while (currentA != nullptr && currentB != nullptr) {
            if (currentA->value < currentB->value) {
                currentA = currentA->next;
            } else if (currentA->value > currentB->value) {
                currentB = currentB->next;
            } else {
                result.insert(currentA->value);
                currentA = currentA->next;
                currentB = currentB->next;
            }
        }
        return result;
    }

    setLinked<T> difference_of_sets(const setLinked<T>& setB) const {
        setLinked<T> result;
        Node* current = head;
        while (current != nullptr) {
            if (!setB.contains(current->value)) {
                result.insert(current->value);
            }
            current = current->next;
        }
        return result;
    }

    bool equality_of_sets(const setLinked<T>& setB) const {
        Node* currentA = head;
        Node* currentB = setB.head;
        while (currentA != nullptr && currentB != nullptr) {
            if (currentA->value != currentB->value) {
                return false;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return (currentA == nullptr && currentB == nullptr);
    }

    void insert(T x) noexcept {
        if (!head || x < head->value) {
            Node* newNode = new Node(x);
            newNode->next = head;
            head = newNode;
            return;
        }
        if (head->value == x) return;

        Node* current = head;
        while (current->next && current->next->value < x) {
            current = current->next;
        }
        if (current->next && current->next->value == x) return; 

        Node* newNode = new Node(x);
        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(T x) noexcept {
        if (!head) return;
        if (head->value == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->value != x) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    bool contains(T x) const noexcept {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == x) {
                return true;
            }
            if (current->value > x) {
                return false;
            }
            current = current->next;
        }
        return false;
    }

    setLinked<T> operator+(const setLinked<T>& setB) const {
        return sum_of_sets(setB);
    }
    setLinked<T> operator-(const setLinked<T>& setB) const {
        return difference_of_sets(setB);
    }
    setLinked<T> operator*(const setLinked<T>& setB) const {
        return intersection_of_sets(setB);
    }
    bool operator==(const setLinked<T>& setB) const {
        return equality_of_sets(setB);
    }

    friend std::ostream& operator<<(std::ostream& os, const setLinked<T>& set) {
        Node* current = set.head;
        while (current != nullptr) {
            os << current->value << " ";
            current = current->next;    
        }
        return os;
    }
};

#endif // SET_LINKED_H
