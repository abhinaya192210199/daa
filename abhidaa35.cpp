#include <stdio.h>
#include <stdbool.h>

#define V 4 
bool isSafe(int vertex, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int vertex) {
    if (vertex == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;

            if (graphColoringUtil(graph, m, color, vertex + 1))
                return true;

            color[vertex] = 0; 
        }
    }

    return false;
}

void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution found:\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    } else {
        printf("Solution does not exist.\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; 

    
    graphColoring(graph, m);

    return 0;
}

