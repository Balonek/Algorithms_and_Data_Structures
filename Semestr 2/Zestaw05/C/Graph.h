#include <fstream>
#include <map>
#include <list>

class ADTgraph {

public:

    ADTgraph () {}

    void addVertex (std::string x, std::string v = "") {
        Node temp;
        temp.value = v;
        graf.insert (std::make_pair (x, temp));
    }

    void removeVertex (std::string x) {
        graf.erase (x);

        for (std::pair<std::string, Node> para : graf) {
            for (typename std::list<Edge>::iterator p = para.second.edges.begin(); p != para.second.edges.end(); ++p) {
                if (p->end_node.compare (x) != 0) {
                    para.second.edges.erase (p);
                    break;
                }
            }
        }
    }

    bool exist (std::string x) {
        return (graf.count (x) == 0) ? false : true;
    }

    bool adjacent (std::string x, std::string y) {
        for (Edge edge : graf.at (x).edges) {
            if (edge.end_node.compare (y) == 0)
                return true;
        }
        return false;
    }
    std::list<std::string> getVertices () {
        std::list<std::string> nodes;
        for (std::pair<std::string, Node> node : graf) {
            nodes.push_back (node.first);
        }
        return nodes;
    }

    std::list<std::string> neighbours (std::string x) {
        std::list<std::string> nodes;
        for (Edge edge : graf.at (x).edges) {
            nodes.push_back (edge.end_node);
        }
        return nodes;
    }
    void addEdge (std::string x, std::string y) {
        if (graf.count(x) == 1 && graf.count(y) == 1) {
            Edge edge;
            edge.end_node = y;
            graf.at (x).edges.push_back (edge);
        }
    }
    void removeEdge (std::string x, std::string y) {
        for (typename std::list<Edge>::iterator p = graf.at (x).edges.begin(); p != graf.at (x).edges.end(); ++p) {
            if (p->end_node == y) {
                graf.at (x).edges.erase (p);
                return;
            }
        }
    }

    void setVertexValue (std::string x, std::string v) {
        graf.at (x).value = v;
    }

    std::string getVertexValue (std::string x) {
        if (graf.count (x) == 0)
            return "";
        return graf.at (x).value;
    }

    void setEdgeValue (std::string x, std::string y, int v) {
        for (Edge edge : graf.at (x).edges) {
            if (edge.end_node == y)
                edge.weight = v;
        }
    }

    int getEdgeValue (std::string x, std::string y) {
        for (Edge edge : graf.at (x).edges) {
            if (edge.end_node == y)
                return edge.weight;
        }
    }

    int size () {
        return graf.size ();
    }

    void save (std::string filename) {
        std::ofstream plik;
        plik.open (filename + ".txt");
        plik << "digraph G {" << std::endl;
        for (std::pair<std::string, Node> para : graf) {
            for (Edge edge : para.second.edges) {
                plik << '\t' << para.first << " -> " << edge.end_node << std::endl;
            }
        }
        plik << "}";
        plik.close ();
    }

private:

    struct Edge {
        int weight = 0;
        std::string end_node;
    };

    struct Node {
        std::string value = "";
        std::list<Edge> edges;
    };

    std::map<std::string, Node> graf;
};