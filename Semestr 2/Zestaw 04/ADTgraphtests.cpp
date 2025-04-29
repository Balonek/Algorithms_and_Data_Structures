#include <iostream>
#include <fstream>
#include <chrono>
#include <stdexcept>
#include "ADTgraph.hpp"

using namespace std;
using namespace std::chrono;

const int N0 = 10;
const int N1 = 200;
const int REPEATS = 1000;
const int N = 200; 

void log_result(ofstream& out, int n, const string& operation, double time) {
    out << n << "," << operation << "," << time << endl;
}

double test_adjacent(ofstream& out) {
    for (int n = N0; n <= N1; n += 10) {
        if (n < 2) continue;

        ADTgraph<200> graph;
        for (int i = 0; i < n; ++i)
            graph.addVertex(i);
        graph.addEdge(0, n - 1);

        auto start = high_resolution_clock::now();
        for (int j = 0; j < REPEATS; ++j) {
            volatile bool result = graph.adjacent(0, n - 1);
        }
        auto end = high_resolution_clock::now();

        double totalTime = duration_cast<nanoseconds>(end - start).count();
        double avg = totalTime / REPEATS;

        log_result(out, n, "adjacent", avg);
        cout << "n = " << n << ", avg time = " << avg << " ns" << endl;
    }
    return 0.0;
}

int main() {
    ofstream outFile("graph_performance.csv");

    if (outFile.is_open()) {
        outFile << "n,operation,time_ns" << endl;
    test_adjacent(outFile);
        outFile.close();
    }

    const int SIZE = 5;
    ADTgraph<SIZE> graph;
    
    cout << "Adding vertices 0, 1, 2\n";
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    
    cout << "Adding edges 0->1, 1->2\n";
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    
    cout << "Checking if 0 and 1 are connected: ";
    cout << (graph.adjacent(0, 1) ? "YES\n" : "NO\n");
    
    cout << "Checking if 0 and 2 are connected: ";
    cout << (graph.adjacent(0, 2) ? "YES\n" : "NO\n");
    
    cout << "Setting vertex 1 value = 42\n";
    graph.setVertexValue(1, 42);
    
    cout << "Value of vertex 1: " << graph.getVertexValue(1) << "\n";
    
    cout << "Setting edge 0->1 value = 99\n";
    graph.setEdgeValue(0, 1, 99);
    
    cout << "Value of edge 0->1: " << graph.getEdgeValue(0, 1) << "\n";
    
    cout << "Neighbors of vertex 0: ";
    int count;
    int* neigh = graph.neighbours(0, count);
    for (int i = 0; i < count; i++) {
        cout << neigh[i] << " ";
    }
    cout << "\n";
    delete[] neigh;
    
    cout << "Graph size: " << graph.sizeOfgraph() << "\n";
    
    cout << "Removing vertex 1\n";
    graph.removeVertex(1);
    
    cout << "Graph size after removal: " << graph.sizeOfgraph() << "\n";
    cout << "Does edge 0->1 still exist? ";
    cout << (graph.adjacent(0, 1) ? "YES\n" : "NO\n");
    cout << "Koniec programu\n";

    return 0;
}