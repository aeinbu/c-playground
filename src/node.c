#include <stdlib.h>
#include <stdio.h>

#include "node.h"

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
void print(struct node *head, intFunc fn) {
    if(head != NULL) {
        fn(head->value);
        print(head->next, fn);
    }
}

// frees all nodes starting from the head node
void freeList(struct node *head) {
    if(head != NULL) {
        freeList(head->next);
        free(head);
    }
}