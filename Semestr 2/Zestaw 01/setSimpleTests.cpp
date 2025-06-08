#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <vector>
#include "setSimple.h"

using namespace std;
using namespace std::chrono;

constexpr int REPEATS = 100;
constexpr int SEED = 42;
constexpr int N0 = 1;
constexpr int N1 = 200;
constexpr int MAX_VAL = 1000;

mt19937 gen(SEED);
uniform_int_distribution<> dis(0, MAX_VAL - 1);

void log_result(ofstream& out, int n, const string& opName, double time) {
    out << n << "," << opName << "," << time << "\n";
}

void test_insert(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> s;
            for (int i = 0; i < n; ++i) s.insert(dis(gen));
            int val = dis(gen);
            auto start = high_resolution_clock::now();
            s.insert(val);
            auto end = high_resolution_clock::now();
            s.remove(val);
            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
        log_result(out, n, "insert_simple", totalTime / REPEATS);
    }
}

void test_remove(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> s;
            vector<int> vals;
            for (int i = 0; i < n; ++i) {
                int val = dis(gen);
                s.insert(val);
                vals.push_back(val);
            }
            if (!vals.empty()) {
                int valToRemove = vals[dis(gen) % vals.size()];
                auto start = high_resolution_clock::now();
                s.remove(valToRemove);
                auto end = high_resolution_clock::now();
                totalTime += duration_cast<nanoseconds>(end - start).count();
            }
        }
        log_result(out, n, "remove_simple", totalTime / REPEATS);
    }
}

void test_contains(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> s;
            vector<int> vals;
            for (int i = 0; i < n; ++i) {
                int val = dis(gen);
                s.insert(val);
                vals.push_back(val);
            }
            if (!vals.empty()) {
                int valToCheck = vals[dis(gen) % vals.size()];
                auto start = high_resolution_clock::now();
                s.contains(valToCheck);
                auto end = high_resolution_clock::now();
                totalTime += duration_cast<nanoseconds>(end - start).count();
            }
        }
        log_result(out, n, "contains_simple", totalTime / REPEATS);
    }
}

void test_sum(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> a, b;
            for (int i = 0; i < n; ++i) {
                a.insert(dis(gen));
                b.insert(dis(gen));
            }
            auto start = high_resolution_clock::now();
            auto c = a + b;
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
        log_result(out, n, "sum_simple", totalTime / REPEATS);
    }
}

void test_intersection(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> a, b;
            for (int i = 0; i < n; ++i) {
                int v = dis(gen);
                a.insert(v);
                b.insert(v);
            }
            auto start = high_resolution_clock::now();
            auto c = a * b;
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
        log_result(out, n, "intersection_simple", totalTime / REPEATS);
    }
}

void test_equality(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> a, b;
            for (int i = 0; i < n; ++i) {
                int v = dis(gen);
                a.insert(v);
                b.insert(v);
            }
            auto start = high_resolution_clock::now();
            bool eq = (a == b);
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
        log_result(out, n, "equality_simple", totalTime / REPEATS);
    }
}

void test_difference(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int r = 0; r < REPEATS; ++r) {
            setSimple<int> a, b;
            for (int i = 0; i < n; ++i) {
                a.insert(dis(gen));
                b.insert(dis(gen));
            }
            auto start = high_resolution_clock::now();
            auto c = a - b;
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
        log_result(out, n, "difference_simple", totalTime / REPEATS);
    }
}

int main() {
    setSimple<int> A, B;

    A.insert(4);
    A.insert(5);
    A.insert(11);
    A.remove(5);

    B.insert(2);
    B.insert(11);

    std::cout << "Zbior A: " << A << std::endl;
    std::cout << "Zbior B: " << B << std::endl;
    std::cout << "A + B: " << (A + B) << std::endl;
    std::cout << "A * B: " << (A * B) << std::endl;
    std::cout << "A - B: " << (A - B) << std::endl;
    std::cout << "Czy A == B: " << (A == B ? "Tak" : "Nie") << std::endl;

    std::cout << "Czy 2 jest w zbiorze A: " << (A.contains(2) ? "Tak" : "Nie") << std::endl;

    ofstream out("results_simple.csv");
    out << "n,operation,time_ns\n";
    test_insert(out);
    test_remove(out);
    test_contains(out);
    test_sum(out);
    test_intersection(out);
    test_equality(out);
    test_difference(out);
    out.close();
}
