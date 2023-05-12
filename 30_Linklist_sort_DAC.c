#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void split(struct Node* head, struct Node** left, struct Node** right);
struct Node* merge(struct Node* left, struct Node* right);
void merge_sort(struct Node** head);

void split(struct Node* head, struct Node** left, struct Node** right) {
    struct Node* slow = head;
    struct Node* fast = head->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    
    struct Node* result = NULL;
    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    
    return result;
}

void merge_sort(struct Node** head) {
    struct Node* current = *head;
    struct Node* left = NULL;
    struct Node* right = NULL;
    
    if (current == NULL || current->next == NULL) return;
    
    split(current, &left, &right);
    
    merge_sort(&left);
    merge_sort(&right);
    
    *head = merge(left, right);
}

void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 4;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 1;
    third->next = fourth;
    
    fourth->data = 3;
    fourth->next = NULL;
    
    printf("Before sorting: ");
    print_list(head);
    
    merge_sort(&head);
    
    printf("After sorting: ");
    print_list(head);
    
    return 0;
}
