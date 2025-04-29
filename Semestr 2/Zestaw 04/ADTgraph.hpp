template<int SIZE>
class ADTgraph{
private:
    int vertices [SIZE];
    int edges [SIZE][SIZE];
    int size = 0;

public:

    ADTgraph () {
        for (int i = 0; i < SIZE; i++) {
            vertices [i] = -1;
            for (int j = 0; j < SIZE; j++) {
                edges [i][j] = -1;
            }
        }
    }

    void addVertex (int x) {
        vertices [x] = 0;
        size++;
    }

    void removeVertex (int x) {
        vertices [x] = -1;
        for (int i = 0; i < SIZE; i++) {
            edges [x][i] = -1;
            edges [i][x] = -1;
        }
        size--;
    }

    bool adjacent (int x, int y) {
        return (edges [x][y] != -1) ? true : false;
    }

    int* neighbours(int x, int& count) {
        count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (edges[x][i] != -1)
                count++;
        }

        int* result = new int[count];
        for (int i = 0, j = 0; i < SIZE; i++) {
            if (edges[x][i] != -1)
                result[j++] = i;
        }

        return result;
    }

    void addEdge (int x, int y) {
        if (vertices [x] != -1 && vertices [y] != -1)
            edges [x][y] = 0;
    }

    void removeEdge (int x, int y) {
        edges [x][y] = -1;
    }

    void setVertexValue (int x, int v) {
        vertices [x] = v;
    }

    int getVertexValue (int x) {
        return vertices [x];
    }

    void setEdgeValue (int x, int y, int v) {
        if (vertices [x] != -1 && vertices [y] != -1)
            edges [x][y] = v;
    }

    int getEdgeValue (int x, int y) {
        return edges [x][y];
    }

    int sizeOfgraph() {
        return size;
    }

};