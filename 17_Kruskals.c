#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 100

struct edge {
    int u;
    int v;
    int weight;
};

struct graph {
    int num_vertices;
    int num_edges;
    struct edge edges[MAX_EDGES];
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare_edges(const void* a, const void* b) {
    struct edge* edge_a = (struct edge*)a;
    struct edge* edge_b = (struct edge*)b;
    return edge_a->weight - edge_b->weight;
}

void kruskal(struct graph* g) {
    struct subset subsets[MAX_VERTICES];
    struct edge result[MAX_VERTICES];
    int i, e = 0;

    for (i = 0; i < g->num_vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(g->edges, g->num_edges, sizeof(struct edge), compare_edges);

    i = 0;
    while (e < g->num_vertices - 1 && i < g->num_edges) {
        struct edge next_edge = g->edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in minimum spanning tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d: %d\n", result[i].u, result[i].v, result[i].weight);
    }
}

int main() {
    struct graph g = {
        .num_vertices = 4,
        .num_edges = 5,
        .edges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
        }
    };

    kruskal(&g);

    return 0;
}
