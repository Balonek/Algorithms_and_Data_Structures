#pragma once
#include <stdexcept>

class CursorList {
private:
    static const int MAX_SIZE = 1000; 
    
    struct Node {
        int x;         
        int next; 
        Node() : x(0), next(-1) {}
    };
    
    Node arr[MAX_SIZE];  
    int head;   
    int tail;  
    int spare;  
    int size_;  

    void initialize() {
        for (int i = 0; i < MAX_SIZE - 1; ++i) {
            arr[i].next = i + 1;
        }
        arr[MAX_SIZE - 1].next = -1;
    }

    int allocate() {
        if (spare == -1) {
            throw std::out_of_range("Overflow");
        }
        int new_node = spare;
        spare = arr[spare].next;
        return new_node;
    }
    void deallocate(int index) {
        arr[index].next = spare; 
        spare = index;
    }

public:
    CursorList() : head(-1), tail(-1), spare(0), size_(0) {
    initialize();
}
    void push_front(int x) {
        int new_node = allocate();
        arr[new_node].x = x;
        arr[new_node].next = head;
        head = new_node;
        if (tail == -1) {
            tail = head;
        }
        size_++;
    }

    int pop_front() {
        if (empty()) throw std::out_of_range("Empty");
        int value = arr[head].x;
        int old_head = head;
        head = arr[head].next;
        if (head == -1) {
            tail = -1;  
        }
        deallocate(old_head);
        size_--;
        return value;
    }

    void push_back(int x) {
        int new_node = allocate();
        arr[new_node].x = x;
        arr[new_node].next = -1;
        if (empty()) {
            head = tail = new_node;
        } else {
            arr[tail].next = new_node;
            tail = new_node;
        }
        size_++;
    }
    
    int pop_back() {
        if (empty()) throw std::out_of_range("Empty");
        int value = arr[tail].x;
        if (head == tail) {
            deallocate(head);
            head = tail = -1;
        } else {
            int current = head;
            while (arr[current].next != tail) {
                current = arr[current].next;
            }
            deallocate(tail);
            tail = current;
            arr[tail].next = -1;
        }
        size_--;
        return value;
    }
    /*void push_back(int x) {
    if (empty()) {
        int new_node = allocate();
        arr[new_node].x = x;
        arr[new_node].next = -1;
        head = tail = new_node; // Lista jest teraz jednoelementowa
    } else {
        int new_node = allocate();
        arr[new_node].x = x;
        arr[new_node].next = -1;
        arr[tail].next = new_node; // Połącz obecny tail z nowym węzłem
        tail = new_node;          // Zaktualizuj tail
    }
    size_++;
}*/

    int size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    int find(int x) const {
        int current = head;
        int position = 0;
        while (current != -1) {
            if (arr[current].x == x) {
                return position;
            }
            current = arr[current].next;
            position++;
        }
        return -1;
    }

    int erase(int i) {
        if (i < 0 || i >= size_) throw std::out_of_range("Index out of range");
        if (i == 0) return pop_front();
        
        int current = head;
        for (int j = 0; j < i - 1; j++) {
            current = arr[current].next;
        }
        
        int to_remove = arr[current].next;
        int value = arr[to_remove].x;
        arr[current].next = arr[to_remove].next;
        if (to_remove == tail) {
            tail = current;
        }
        deallocate(to_remove);
        size_--;
        return value;
    }

    void insert(int i, int x) {
        if (i < 0 || i > size_) throw std::out_of_range("Index out of range"); 
        if (i == 0) {
            push_front(x);
            return;                
        }

        int current = head;
        for (int j = 0; j < i - 1; j++) {
            current = arr[current].next;
        }
        int new_node = allocate();
        arr[new_node].x = x; 
        // uwazac by nie nadpisywac 
        arr[new_node].next = arr[current].next;
        arr[current].next = new_node;
        if (i == size_) tail = new_node;
        size_++;
    }

    int remove(int x) {
        int count = 0;
        while (head != -1 && arr[head].x == x) {
            pop_front();
            count++;
        }
        
        if (head != -1) {
            int current = head;
                while (arr[current].next != -1) {
                if (arr[arr[current].next].x == x) {
 
                    int to_remove = arr[current].next;
                    arr[current].next = arr[to_remove].next;

                    if (to_remove == tail) {
                        tail = current;
                    }
                    deallocate(to_remove);
                    size_--;
                    count++;
                } else {
                    current = arr[current].next;        
                }
            }
        }
        return count;
    }
};