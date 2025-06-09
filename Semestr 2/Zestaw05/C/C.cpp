#include <iostream>
#include <list>
#include <map>
#include "Graph.h"
using namespace std;

void topologicalSortUtil(ADTgraph& graph, string v, map<string, bool>& seen, list<string>& stack) {

    seen[v] = true;

    for(string i : graph.neighbours(v)){
        if(!seen[i]){
            topologicalSortUtil(graph,i,seen,stack);
        }
    }
    stack.push_front(v);

}

list<string> topologicalSort(ADTgraph& adTgraph){
    map<string,bool> seen;
    list<string> stack;

    for(string i : adTgraph.getVertices()){
        seen[i] = false;
    }

    for(string i : adTgraph.getVertices()){
        if(!seen[i]){
            topologicalSortUtil(adTgraph,i,seen,stack);
        }
    }
    return stack;

}

int main() {

    ADTgraph graf;

    graf.addVertex ("1", "Wez 1 szklanke proszku");
    graf.addVertex ("2", "Wez 1 lyzke oleju");
    graf.addVertex ("3", "Wez 3/4 szklanki mleka");
    graf.addVertex ("4", "Wez 1 jajko");
    graf.addVertex ("5", "Zmieszaj skladniki");
    graf.addVertex ("6", "Podgrzej syrop klonowy");
    graf.addVertex ("7", "Zjedz rumiany nalesnik polany cieplym syropem klonowym");
    graf.addVertex ("8", "Nagrzej patelnie");
    graf.addVertex ("9", "Wylej czesc ciasta nalesnikowego na patelnie");
    graf.addVertex ("10", "Gdy nalesnik jest rumiany od spodu przewroc go i podpiecz z drugiej strony");

    graf.addEdge("1", "5");
    graf.addEdge("2", "5");
    graf.addEdge("3", "5");
    graf.addEdge("4", "5");
    graf.addEdge("5", "6");
    graf.addEdge("5", "9");
    graf.addEdge("6", "9");
    graf.addEdge("9", "10");
    graf.addEdge("10", "7");
    graf.addEdge("6", "7");

    cout << "\nKolejnosc wykonywania krokow" << endl << endl;

    int i = 1;
    for (string node : topologicalSort(graf)) {
        cout << i << ". " << graf.getVertexValue (node) << endl;
        i++;
    }

    return 0;
}