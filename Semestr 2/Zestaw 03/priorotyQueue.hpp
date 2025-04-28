#ifndef PRIOROTY_QUEUE_H
#define PRIOROTY_QUEUE_H

#include <iostream>
#include <stdexcept>
const int N = 500;

template<class T>
class priorotyQueue {
private:
    bool arr[N];

public:
    priorotyQueue() {
        for (int i = 0; i < N; i++) {
            arr[i] = false;
        }
    }

    int p (int x) {
        return x;
    }

    void insert(T x) {
        if (x >= 0 && x < N) {
            arr[x] = true;
        }
    }

    int remove() {
        int i = 0;
        while(i < N && arr[i] == false){
            i++;
        }
        if (i >= N) {
            throw std::underflow_error("Queue is empty");
        }
        arr[i] = false;
        return i;
    }

    friend std::ostream& operator<<(std::ostream& os, const priorotyQueue<T>& set) {
        os << "{ ";
        for (int i = 0; i < N; i++) {
            if (set.arr[i]) os << i << " ";
        }
        os << "}";
        return os;
    }

};

#endif