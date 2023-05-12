#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph {
    int num_nodes;
    int adj_matrix[MAX_NODES][MAX_NODES];
};

void initialize_graph(struct Graph* graph, int num_nodes) {
    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(struct Graph* graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

void dfs_visit(struct Graph* graph, int node, int visited[MAX_NODES], int component[MAX_NODES], int* component_count) {
    visited[node] = 1;
    component[node] = *component_count;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adj_matrix[node][i] == 1 && visited[i] == 0) {
            dfs_visit(graph, i, visited, component, component_count);
        }
    }
}

void dfs(struct Graph* graph, int visited[MAX_NODES], int component[MAX_NODES], int* component_count) {
    for (int i = 0; i < graph->num_nodes; i++) {
        visited[i] = 0;
        component[i] = -1;
    }
    *component_count = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (visited[i] == 0) {
            (*component_count)++;
            dfs_visit(graph, i, visited, component, component_count);
        }
    }
}

int main() {
    int num_nodes = 7;
    struct Graph graph;
    initialize_graph(&graph, num_nodes);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);
    add_edge(&graph, 5, 6);
    int visited[MAX_NODES];
    int component[MAX_NODES];
    int component_count;
    dfs(&graph, visited, component, &component_count);
    for (int i = 1; i <= component_count; i++) {
        printf("Component %d:", i);
        for (int j = 0; j < graph.num_nodes; j++) {
            if (component[j] == i - 1) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
    return 0;
}
