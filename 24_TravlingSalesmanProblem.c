#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int num_vertices;
int min_path = INT_MAX;

void tsp(int start_vertex, int current_vertex, int count, int path_cost) {
    if (count == num_vertices && graph[current_vertex][start_vertex] != 0) {
        // All vertices have been visited and we can return to the start vertex
        min_path = path_cost + graph[current_vertex][start_vertex];
        return;
    }
    
    for (int i = 0; i < num_vertices; i++) {
        if (graph[current_vertex][i] != 0 && visited[i] == 0) {
            visited[i] = 1;
            tsp(start_vertex, i, count + 1, path_cost + graph[current_vertex][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    // Read in the graph from input
    scanf("%d", &num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Start at each vertex and run the tsp function
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 1;
        tsp(i, i, 1, 0);
        visited[i] = 0;
    }
    
    // Output the minimum path found
    printf("Minimum path: %d\n", min_path);
    
    return 0;
}
