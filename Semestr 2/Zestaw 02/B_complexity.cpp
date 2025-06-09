#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>
#include "setHashed.hpp"

#define N 1000
#define MEASUREMENTS 30.0

using namespace std;
using namespace std::chrono;

template<typename Func>
long long measure_time(Func func) {
    const auto beg = high_resolution_clock::now();
    func();
    const auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - beg).count();
}

void showInsertComplexity(std::ostream& out) {
    for (int i = 0; i < N; ++i) {
        double totalDuration = 0.0;
        setHashed<int>* mySet = new setHashed<int>();

        for (int j = 0; j < 50 * N; ++j) {
            mySet->insertElement(j);
        }

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] { mySet->insertElement(0); }) / MEASUREMENTS;
            mySet->deleteElement(i);
        }

        out << "InsertComplexity," << i << "," << totalDuration << "\n";
        delete mySet;
    }
}

void showRemoveComplexity(std::ostream& out) {
    setHashed<int>* mySet = new setHashed<int>();

    for (int i = 1; i < N; ++i) {
        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { mySet->deleteElement(i); });
            totalDuration += duration;
        }
        out << "RemoveComplexity," << i << "," << totalDuration / MEASUREMENTS << "\n";
    }

    delete mySet;
}

void showSumComplexity(std::ostream& out) {
    for (int i = 1; i < N; ++i) {
        setHashed<int> set1;
        setHashed<int> set2;

        for (int j = 0; j < i; ++j) {
            set1.insertElement(j);
            set2.insertElement(i + j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                volatile auto result = set1 + set2;
            });
        }

        out << "SumComplexity," << i << "," << totalDuration / MEASUREMENTS << "\n";
    }
}

void showIntersectionComplexity(std::ostream& out) {
    for (int i = 1; i < N; ++i) {
        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            set1->insertElement(j);
            set2->insertElement(j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] { *set1 * *set2; }) / MEASUREMENTS;
        }

        delete set1;
        delete set2;

        out << "IntersectionComplexity," << i << "," << totalDuration << "\n";
    }
}

void showContainsComplexity(std::ostream& out) {
    for (int i = 1; i < N; ++i) {
        setHashed<int>* mySet = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            mySet->insertElement(j);
        }

        double totalDuration = 0.0;
        for (int j = 1; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { mySet->contains(i + i); });
            totalDuration += duration;
        }

        delete mySet;
        out << "ContainsComplexity," << i << "," << totalDuration / MEASUREMENTS << "\n";
    }
}

void showEqualityComplexity(std::ostream& out) {
    for (int i = 1; i < N; ++i) {
        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            set1->insertElement(j);
            set2->insertElement(j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] { (*set1 == *set2); }) / MEASUREMENTS;
        }

        delete set1;
        delete set2;
        out << "EqualityComplexity," << i << "," << totalDuration << "\n";
    }
}

void showDifferenceComplexity(std::ostream& out) {
    for (int i = 1; i < N; ++i) {
        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            set1->insertElement(j);
            set2->insertElement(j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] { *set1 - *set2; }) / MEASUREMENTS;
        }

        out << "DifferenceComplexity," << i << "," << totalDuration << "\n";

        delete set1;
        delete set2;
    }
}

int main() {
    std::ofstream csvOut("complexity_results.csv");
    csvOut << "Operation,InputSize,Nanoseconds\n";

    showInsertComplexity(csvOut);
    showRemoveComplexity(csvOut);
    showSumComplexity(csvOut);
    showIntersectionComplexity(csvOut);
    showContainsComplexity(csvOut);
    showEqualityComplexity(csvOut);
    showDifferenceComplexity(csvOut);

    csvOut.close();

    std::cout << "Wyniki zapisano do complexity_results.csv\n";
    return 0;
}