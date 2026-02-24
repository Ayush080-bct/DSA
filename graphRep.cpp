#include <iostream>
using namespace std;

// Function to get index of a vertex
int getIndex(char vertices[], int V, char c) {
    for(int i=0; i<V; i++)
        if(vertices[i] == c) return i;
    return -1; // not found
}

// Function to compute transitive closure using Warshall's algorithm
void transitiveClosure(int V, int adjMatrix[10][10]) {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adjMatrix[i][j] = adjMatrix[i][j] || (adjMatrix[i][k] && adjMatrix[k][j]);
            }
        }
    }
}

// Function to print adjacency matrix
void printMatrix(char vertices[], int V, int adjMatrix[10][10]) {
    cout << "  ";
    for(int i=0; i<V; i++) cout << vertices[i] << " ";
    cout << endl;

    for(int i=0; i<V; i++) {
        cout << vertices[i] << " ";
        for(int j=0; j<V; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    char vertices[] = {'A','B','C','D','E'};
    char edges[][2] = { {'A','B'}, {'A','C'}, {'A','D'}, {'B','E'}, {'C','B'}, {'C','E'} };

    int V = sizeof(vertices)/sizeof(vertices[0]);
    int E = sizeof(edges)/sizeof(edges[0]);

    int adjMatrix[10][10] = {0}; // initialize all to 0

    // Fill adjacency matrix
    for(int k=0; k<E; k++) {
        int u = getIndex(vertices, V, edges[k][0]);
        int v = getIndex(vertices, V, edges[k][1]);
        if(u != -1 && v != -1)
            adjMatrix[u][v] = 1; // directed graph
    }

    cout << "Original Adjacency Matrix:\n";
    printMatrix(vertices, V, adjMatrix);

    // Compute transitive closure
    transitiveClosure(V, adjMatrix);

    cout << "\nTransitive Closure:\n";
    printMatrix(vertices, V, adjMatrix);

    return 0;
}
