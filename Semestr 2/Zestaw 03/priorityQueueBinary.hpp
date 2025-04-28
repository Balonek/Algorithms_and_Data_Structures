#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>

const int N = 1000;

template<class T>
class priorityQueueBinary {
private:
    T heap[N];

public:
    int size;

    priorityQueueBinary() : size(0) {}

    void insert(T value) {
        if (size >= N) {
            throw std::overflow_error("Kopiec jest pełny");
        }
        int i = size++;
        int j = (i - 1) / 2;

        while (i > 0 && heap[j] > value) {
            heap[i] = heap[j];
            i = j;
            j = (i - 1) / 2;
        }

        heap[i] = value;
    }

    T remove() {
        if (size == 0) throw std::underflow_error("Kopiec jest pusty");

        T removed = heap[0];
        T last_value = heap[--size];
        int i = 0;
        int j = 1;

        while (j < size) {
            if (j + 1 < size && heap[j + 1] < heap[j]) {
                j++;
            }

            if (last_value <= heap[j]) {
                break;
            }

            heap[i] = heap[j];
            i = j;
            j = 2 * i + 1;
        }

        heap[i] = last_value;
        return removed;
    }

    void print() const {
        std::cout << "{ ";
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << "}";
    }

    friend std::ostream& operator<<(std::ostream& os, const priorityQueueBinary<T>& q) {
        os << "{ ";
        for (int i = 0; i < q.size; i++) {
            os << q.heap[i] << " ";
        }
        os << "}";
        return os;
    }
};

#endif
