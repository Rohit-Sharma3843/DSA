#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class graph {
public:
    int vertices;
    int** matrix;
    graph(int vertices) {
        this->vertices = vertices;
        matrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            matrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                matrix[i][j] = 0;
            }
        }

        int edges, x, y, w;
        cout << "Enter the number of edges: ";
        cin >> edges;
        for (int i = 0; i < edges; i++) {
            cout << "Enter the edge in (u, v) format: ";
            cin >> x >> y;
            cout << "Enter the weight of the edge (" << x << ", " << y << "): ";
            cin >> w;
            matrix[x][y] = w;
            matrix[y][x] = w;
        }
    }
    int find_min(vector<bool>& visited, vector<int>& dist) {
        int min = INT_MAX, index = -1;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                index = i;
            }
        }
        return index;
    }
    void dijkstra(int source) {
        vector<int> dist(vertices, INT_MAX); 
        vector<bool> visited(vertices, false);
        dist[source] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = find_min(visited, dist);
            if (u == -1) break;
            visited[u] = true;
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && matrix[u][v] && dist[u] != INT_MAX && dist[u] + matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + matrix[u][v];
                }
            }
        }

        cout << "\nShortest distances from node " << source << ":\n";
        for (int i = 0; i < vertices; i++) {
            cout << "To node " << i << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
        }
    }
    ~graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    graph g(v);
    int source;
    cout << "\nEnter the source vertex for Dijkstra's algorithm: ";
    cin >> source;
    g.dijkstra(source);
    return 0;
}
