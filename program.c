#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int value;
};

// returns the new head node
struct node *prepend(struct node *head, int value) {
    struct node *newHead = malloc(sizeof(struct node));
    newHead->next = head;
    newHead->value = value;
    return newHead;
}

// returns the original head node
struct node *append(struct node *head, int value) {
    if(head != NULL) {
        head->next = append(head->next, value);
        return head;
    }

    struct node *newTail = malloc(sizeof(struct node));
    newTail->next = NULL;
    newTail->value = value;

    return newTail;
}

// prints all nodes starting from the head node
void print(struct node *head) {
    if(head != NULL) {
        printf("%d\n", head->value);
        print(head->next);
    }
}

// frees all nodes starting from the head node
void freeList(struct node *head) {
    if(head != NULL) {
        freeList(head->next);
        free(head);
    }
}

int main(int argc, char *argv[]) {
    struct node *head = NULL;

    for(int i = 1; i < 10; i++)
    {
        head = prepend(head, i);
        // head = append(head, i);
    }
    
    
    printf("Listing all nodes:\n");
    print(head);

    printf("Freeing nodes:\n");
    freeList(head);

    exit(-2);
    return -1;
}