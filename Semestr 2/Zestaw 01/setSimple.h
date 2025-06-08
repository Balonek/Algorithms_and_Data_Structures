#ifndef SET_SIMPLE_H
#define SET_SIMPLE_H

#include <iostream>

const int N = 800;

template<class T>
class setSimple {
private:
    bool arr[N];

public:
    setSimple() {
        for (int i = 0; i < N; i++) {
            arr[i] = false;
        }
    }

    void sum_of_sets(const setSimple<T>& setB, setSimple<T>& result) const {
        for (int i = 0; i < N; i++) {
            result.arr[i] = arr[i] || setB.arr[i];
        }
    }

    void intersection_of_sets(const setSimple<T>& setB, setSimple<T>& result) const {
        for (int i = 0; i < N; i++) {
            result.arr[i] = arr[i] && setB.arr[i];
        }
    }

    void difference_of_sets(const setSimple<T>& setB, setSimple<T>& result) const {
        for (int i = 0; i < N; i++) {
            result.arr[i] = arr[i] && !setB.arr[i];
        }
    }

    bool equality_of_sets(const setSimple<T>& setB) const {
        for (int i = 0; i < N; i++) {
            if (arr[i] != setB.arr[i]) return false;
        }
        return true;
    }

    void insert(T x) {
        if (x >= 0 && x < N) arr[x] = true;
    }

    void remove(T x) {
        if (x >= 0 && x < N) arr[x] = false;
    }

    bool contains(T x) const noexcept {
        if (x >= 0 && x < N) return arr[x];
        return false;
    }

    bool operator==(const setSimple<T>& setB) const {
        return equality_of_sets(setB);
    }

    friend std::ostream& operator<<(std::ostream& os, const setSimple<T>& set) {
        os << "{ ";
        for (int i = 0; i < N; i++) {
            if (set.arr[i]) os << i << " ";
        }
        os << "}";
        return os;
    }

    setSimple<T> operator+(const setSimple<T>& setB) const {
        setSimple<T> result;
        sum_of_sets(setB, result);
        return result;
    }

    setSimple<T> operator*(const setSimple<T>& setB) const {
        setSimple<T> result;
        intersection_of_sets(setB, result);
        return result;
    }

    setSimple<T> operator-(const setSimple<T>& setB) const {
        setSimple<T> result;
        difference_of_sets(setB, result);
        return result;
    }
};

#endif
