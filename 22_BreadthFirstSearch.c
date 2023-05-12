#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Define a graph node struct
struct Node {
    int id;
    int distance;
    int parent;
    bool visited;
};

// Define a queue struct
struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
};

// Create a new queue
struct Queue *create_queue(int capacity) {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (int *) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if queue is full
bool is_full(struct Queue *queue) {
    return queue->size == queue->capacity;
}

// Check if queue is empty
bool is_empty(struct Queue *queue) {
    return queue->size == 0;
}

// Enqueue a node to the queue
void enqueue(struct Queue *queue, int node_id) {
    if (is_full(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = node_id;
    queue->size++;
}

// Dequeue a node from the queue
int dequeue(struct Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    int node_id = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return node_id;
}

// Create a new graph node
struct Node *create_node(int id) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->id = id;
    node->distance = -1;
    node->parent = -1;
    node->visited = false;
    return node;
}

// Add an edge to the graph
void add_edge(int graph[MAX_NODES][MAX_NODES], int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

// Perform BFS on the graph
void bfs(int graph[MAX_NODES][MAX_NODES], int start_node, int end_node, int num_nodes) {
    struct Queue *queue = create_queue(num_nodes);

    // Create array of nodes
    struct Node *nodes[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = create_node(i);
    }

    // Mark start node as visited and add to queue
    nodes[start_node]->visited = true;
    nodes[start_node]->distance = 0;
    enqueue(queue, start_node);

    // Traverse graph using BFS
    while (!is_empty(queue)) {
        int current_node_id = dequeue(queue);

        // Stop BFS if end node is found
        if (current_node_id == end_node) {
            break;
        }

        // Visit all adjacent nodes of current node
        for (int i = 0; i < num_nodes; i++) {
            if (graph[current_node_id][i] == 1 && !nodes[i]->visited) {
                nodes[i]->visited = true;
                nodes[i]->distance = nodes[current_node_id]->distance + 1;
                nodes[i]->parent = current_node_id;
                enqueue(queue, i);
            }
        }
    }

