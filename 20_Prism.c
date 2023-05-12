#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct graph {
    int num_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
};

int min_key(int key[], int visited[], int num_vertices) {
    int min = INT_MAX, min_index;
    int v;

    for (v = 0; v < num_vertices; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void print_mst(int parent[], struct graph* g) {
    int i;

    printf("Edge\tWeight\n");
    for (i = 1; i < g->num_vertices; i++) {
        printf("%d - %d\t%d\n", parent[i], i, g->adjacency_matrix[i][parent[i]]);
    }
}

void prim(struct graph* g) {
    int parent[MAX_VERTICES], key[MAX_VERTICES], visited[MAX_VERTICES];
    int i, count, u, v;

    for (i = 0; i < g->num_vertices; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < g->num_vertices - 1; count++) {
        u = min_key(key, visited, g->num_vertices);
        visited[u] = 1;

        for (v = 0; v < g->num_vertices; v++) {
            if (g->adjacency_matrix[u][v] && visited[v] == 0 && g->adjacency_matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adjacency_matrix[u][v];
            }
        }
    }

    print_mst(parent, g);
}

int main() {
    struct graph g = {
        .num_vertices = 9,
        .adjacency_matrix = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
        }
    };

    prim(&g);

    return 0;
}
