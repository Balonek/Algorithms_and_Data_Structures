#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;
const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int src, const vector<vector<pair<int,int>>>& adj,vector<int>& parent){
    int n = adj.size();
    vector<int> dist(n, INF);
    dist[src] = 0;
    parent.assign(n,-1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> priorityQueue;
    priorityQueue.push({0,src});

    while(!priorityQueue.empty()){
        auto[d, u] = priorityQueue.top();
        priorityQueue.pop();

        if(d > dist[u]){
            continue;
        }
        for(auto [v,w] : adj[u]){
            int nd = d + w;
            if(nd < dist[v]){
                dist[v] = nd;
                parent[v] = u;
                priorityQueue.push({nd,v});
            }
        }

    }
    return  dist;
}

int main() {
    unordered_map<char,int> id;
    string letters = "ABCDEFGHIJ";

    for(int i=0;i<10;i++){
        id[ letters[i] ] = i;
    }

    vector<vector<pair<int,int>>> adj(10);

    auto add = [&](char a, char b, int w){
        adj[ id[a] ].push_back({ id[b], w });
        adj[ id[b] ].push_back({ id[a], w });
    };

    add('A','B', 3);
    add('B','D', 1);
    add('B','C', 2);
    add('C','H', 2);
    add('D','E', 1);
    add('E','F', 1);
    add('G','F', 1);
    add('G','H', 1);
    add('H','I', 2);
    add('H','J', 1);
    add('H','F', 2);

    vector<int> parent;
    auto dist = dijkstra(id['I'], adj, parent);

    int target = id['D'];
    cout<<"Najkrotszy czas z I do D: " << dist[target] <<endl;

    vector<char> path;
    for( int v = target; v != -1; v = parent[v]){
        path.push_back(letters[v]);
    }
    reverse(path.begin(), path.end());

    cout << "sciezka: ";
    for (char c : path) cout << c << " ";
    cout << "\n";

    return 0;
}