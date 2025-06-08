#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <vector>
#include "setLinked.h"

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

double test_insert(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;

        for (int j = 0; j < REPEATS; ++j) {
            auto* set = new setLinked<int>();
            for (int i = 0; i < n; ++i) set->insert(dis(gen));
            int val = dis(gen);
            auto start = high_resolution_clock::now();
            set->insert(val);
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
            set->remove(val);
            delete set;
        }

        double avg = totalTime / REPEATS;
        log_result(out, n, "insert", avg);
    }
    return 0.0;
}

double test_remove(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;

        for (int j = 0; j < REPEATS; ++j) {
            auto* set = new setLinked<int>();
            vector<int> vals;
            for (int i = 0; i < n; ++i) {
                int val = dis(gen);
                set->insert(val);
                vals.push_back(val);
            }
            if (!vals.empty()) {
                int valToRemove = vals[dis(gen) % vals.size()];
                auto start = high_resolution_clock::now();
                set->remove(valToRemove);
                auto end = high_resolution_clock::now();
                totalTime += duration_cast<nanoseconds>(end - start).count();
            }
            delete set;
        }

        double avg = totalTime / REPEATS;
        log_result(out, n, "remove", avg);
    }
    return 0.0;
}

double test_sum(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int j = 0; j < REPEATS; ++j) {
            auto* a = new setLinked<int>();
            auto* b = new setLinked<int>();
            for (int i = 0; i < n; ++i) {
                a->insert(dis(gen));
                b->insert(dis(gen));
            }
            auto start = high_resolution_clock::now();
            auto c = *a + *b;
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
            delete a;
            delete b;
        }
        double avg = totalTime / REPEATS;
        log_result(out, n, "sum", avg);
    }
    return 0.0;
}

double test_intersection(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int j = 0; j < REPEATS; ++j) {
            auto* a = new setLinked<int>();
            auto* b = new setLinked<int>();
            for (int i = 0; i < n; ++i) {
                int val = dis(gen);
                a->insert(val);
                b->insert(val);
            }
            auto start = high_resolution_clock::now();
            auto c = *a * *b;
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
            delete a;
            delete b;
        }
        double avg = totalTime / REPEATS;
        log_result(out, n, "intersection", avg);
    }
    return 0.0;
}

double test_contains(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int j = 0; j < REPEATS; ++j) {
            auto* set = new setLinked<int>();
            vector<int> vals;
            for (int i = 0; i < n; ++i) {
                int val = dis(gen);
                set->insert(val);
                vals.push_back(val);
            }
            if (!vals.empty()) {
                int valToCheck = vals[dis(gen) % vals.size()];
                auto start = high_resolution_clock::now();
                set->contains(valToCheck);
                auto end = high_resolution_clock::now();
                totalTime += duration_cast<nanoseconds>(end - start).count();
            }
            delete set;
        }
        double avg = totalTime / REPEATS;
        log_result(out, n, "contains", avg);
    }
    return 0.0;
}

double test_equality(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int j = 0; j < REPEATS; ++j) {
            auto* a = new setLinked<int>();
            auto* b = new setLinked<int>();
            for (int i = 0; i < n; ++i) {
                int val = dis(gen);
                a->insert(val);
                b->insert(val);
            }
            auto start = high_resolution_clock::now();
            bool equal = (*a == *b);
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
            delete a;
            delete b;
        }
        double avg = totalTime / REPEATS;
        log_result(out, n, "equality", avg);
    }
    return 0.0;
}

double test_difference(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;
        for (int j = 0; j < REPEATS; ++j) {
            auto* a = new setLinked<int>();
            auto* b = new setLinked<int>();
            for (int i = 0; i < n; ++i) {
                a->insert(dis(gen));
                b->insert(dis(gen));
            }
            auto start = high_resolution_clock::now();
            auto c = *a - *b;
            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
            delete a;
            delete b;
        }
        double avg = totalTime / REPEATS;
        log_result(out, n, "difference", avg);
    }
    return 0.0;
}

int main() {
    setLinked<int> A, B;

    A.insert(4);
    A.insert(5);
    A.insert(11);
    A.remove(5);

    B.insert(2);
    B.insert(11);

    std::cout << "Zbior A: " << A << std::endl;
    std::cout << "Zbior B: " << B << std::endl;

    std::cout << "A + B: " << A + B << std::endl;
    std::cout << "A * B: " << A * B << std::endl;
    std::cout << "A - B: " << A - B << std::endl;
    std::cout << "Czy A == B: " << (A == B ? "Tak" : "Nie") << std::endl;

    bool testequalityv2 = A.contains(2);
    std::cout << "Czy 2 jest w zbiorze A: " << (testequalityv2 ? "Tak" : "Nie") << std::endl;

    ofstream outFile("results.csv");
    outFile << "n,operation,time_ns\n"; 

    test_insert(outFile);
    test_remove(outFile);
    test_sum(outFile);
    test_intersection(outFile);
    test_contains(outFile);
    test_equality(outFile);
    test_difference(outFile);

    outFile.close();
    return 0;
}