#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <vector>
#include "priorityQueueBinary.hpp"

using namespace std;
using namespace std::chrono;

constexpr int REPEATS = 500;
constexpr int SEED = 42;
constexpr int N0 = 1;
constexpr int N1 = 1000;
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
            try {
                auto* set = new priorityQueueBinary<int>();
                for (int i = 0; i < n; ++i) set->insert(dis(gen));
                int val = dis(gen);
                auto start = high_resolution_clock::now();
                set->insert(val);
                auto end = high_resolution_clock::now();
                totalTime += duration_cast<nanoseconds>(end - start).count();
                delete set;
            } catch (const std::exception& e) {
                cerr << "Error in test_insert at n=" << n << ", j=" << j << ": " << e.what() << endl;
                return 1.0;
            }
        }

        double avg = totalTime / REPEATS;
        log_result(out, n, "insert", avg);
        out.flush();
        if (n % 10 == 0) cout << "Completed insert test for n=" << n << endl;
    }
    return 0.0;
}

double test_remove(ofstream& out) {
    for (int n = N0; n < N1; ++n) {
        double totalTime = 0.0;

        for (int j = 0; j < REPEATS; ++j) {
            try {
                auto* set = new priorityQueueBinary<int>();
                vector<int> vals;
                
                for (int i = 0; i < n && i < N; ++i) {
                    int val = dis(gen);
                    set->insert(val);
                    vals.push_back(val);
                }
                
                if (!vals.empty()) {
                    auto start = high_resolution_clock::now();
                    set->remove();
                    auto end = high_resolution_clock::now();
                    totalTime += duration_cast<nanoseconds>(end - start).count();
                }
                delete set;
            } catch (const std::exception& e) {
                cerr << "Error in test_remove at n=" << n << ", j=" << j << ": " << e.what() << endl;
                return 1.0;
            }
        }

        double avg = totalTime / REPEATS;
        log_result(out, n, "remove", avg);
        out.flush(); 
    }
    return 0.0;
}


int main() {
    priorityQueueBinary<int> A;
    std::cout << "Kopiec A: " << A << std::endl;
    A.insert(4);
    A.insert(5);
    A.insert(11);
    std::cout << "Kopiec A: " << A << std::endl;
    A.remove();
    std::cout << "Kopiec A: " << A << std::endl;
    A.insert(2);
    A.remove();
    A.insert(15);
    std::cout << "Kopiec A: " << A << std::endl;

    ofstream outFile("resultsB.csv");
    if (!outFile.is_open()) {
        cerr << "Nie można otworzyć pliku results.csv!" << endl;
        return 1;
    }
    
    outFile << "n,operation,time_ns\n";
    outFile.flush(); 
    
    test_insert(outFile);
    outFile.flush();
    
    test_remove(outFile);
    outFile.flush(); 
    
    outFile.close();
    
    return 0;
}