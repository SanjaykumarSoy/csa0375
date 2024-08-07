#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int main() {
    int edges = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++) {
            if (graph[i][j] == 1) {
                edges++;
            }
        }
    }
    printf("Minimum number of edges in the graph: %d\n", edges);
    return 0;
}
