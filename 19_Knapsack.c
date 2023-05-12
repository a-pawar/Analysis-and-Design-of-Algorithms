#include <stdio.h>

#define MAX_ITEMS 100

struct item {
    int weight;
    int value;
    double value_per_weight;
};

int compare(const void *a, const void *b) {
    double diff = ((struct item *) b)->value_per_weight - ((struct item *) a)->value_per_weight;
    return diff > 0 ? 1 : (diff < 0 ? -1 : 0);
}

int knapsack_greedy(int capacity, struct item items[], int num_items) {
    qsort(items, num_items, sizeof(struct item), compare);

    int i;
    double total_value = 0;
    for (i = 0; i < num_items; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value_per_weight * capacity;
            break;
        }
    }

    return (int) total_value;
}

int main() {
    int capacity = 50;

    struct item items[MAX_ITEMS] = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int num_items = 3;

    int max_value = knapsack_greedy(capacity, items, num_items);

    printf("Maximum value: %d\n", max_value);

    return 0;
}
