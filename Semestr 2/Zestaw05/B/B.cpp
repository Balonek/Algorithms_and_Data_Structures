#include <iostream>
#include <fstream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_set<string> load_words(const string& filename){
    unordered_set<string> words;
    ifstream file(filename);
    string word;
    while (file >> word){
        if(word.length() == 4) words.insert(word);
    }
    return words;
}
bool one_letter_diff(const string& a, const string& b) {
    int diff = 0;
    for(int i=0; i < 4; ++i){
        if (a[i] != b[i]) ++diff;
    }
    return diff == 1;
}

unordered_map<string, vector<string>> build_graph(const unordered_set<string>& words) {
    unordered_map<string, vector<string>> graph;
    for (const string& word1 : words) {
        for (const string& word2 : words) {
            if(one_letter_diff(word1,word2)){
                graph[word1].push_back(word2);
            }
        }
    }
    return graph;
}


vector<string> bfs(const string& start, const string& end, const unordered_map<string, vector<string>>& graph) {
    unordered_set<string> visited;
    queue<pair<string, vector<string>>> queue;

    queue.push({start,{start}});
    visited.insert(start);

    while (!queue.empty()){
        auto [current, path] = queue.front();
        queue.pop();

        if(current == end) return path;

        for (const string& neighbor : graph.at(current)) {
            if(visited.count(neighbor) == 0){
                visited.insert(neighbor);
                vector<string> new_path = path;
                new_path.push_back(neighbor);
                queue.push({neighbor, new_path});
            }
        }
    }
    return {};
}

int main() {
    unordered_set<string> word_set = load_words("words.txt");

    string start = "rowy";
    string end = "atom";

    unordered_map<string, vector<string>> graph = build_graph(word_set);
    vector<string> path = bfs(start, end, graph);

    if (!path.empty()) {
        cout << "Najkrotsza sciezka od \"" << start << "\" do \"" << end << "\":" << endl;
        for (const string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    } else {
        cout << "Nie znaleziono ściezki. " << endl;
    }

    return 0;
}