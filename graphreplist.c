#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Node structure for adjacency list
typedef struct Node {
    char vertex;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to get index of a vertex
int getIndex(char vertices[], int V, char c) {
    for(int i = 0; i < V; i++)
        if(vertices[i] == c) return i;
    return -1;
}

// Function to create adjacency list
void createAdjList(char vertices[], int V, char edges[][2], int E, Node* adjList[]) {
    // Initialize adjacency list
    for(int i = 0; i < V; i++)
        adjList[i] = NULL;

    // Fill adjacency list
    for(int k = 0; k < E; k++) {
        int u = getIndex(vertices, V, edges[k][0]);
        int v = getIndex(vertices, V, edges[k][1]);
        if(u != -1 && v != -1) {
            Node* newNode = createNode(vertices[v]);
            newNode->next = adjList[u];
            adjList[u] = newNode; // insert at beginning
        }
    }
}

// Function to print adjacency list
void printAdjList(char vertices[], int V, Node* adjList[]) {
    for(int i = 0; i < V; i++) {
        printf("%c: ", vertices[i]);
        Node* temp = adjList[i];
        while(temp != NULL) {
            printf("%c -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    char vertices[] = {'A','B','C','D','E'};
    char edges[][2] = { {'A','B'}, {'A','C'}, {'A','D'}, {'B','E'}, {'C','B'}, {'C','E'} };

    int V = sizeof(vertices)/sizeof(vertices[0]);
    int E = sizeof(edges)/sizeof(edges[0]);

    Node* adjList[MAX]; // array of linked lists

    createAdjList(vertices, V, edges, E, adjList);
    printAdjList(vertices, V, adjList);

    return 0;
}
