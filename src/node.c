#include <stdlib.h>
#include <stdio.h>

#include "node.h"

// returns the new head node
node *prepend(node *head, int value) {
    node *newHead = malloc(sizeof(node));
    newHead->next = head;
    newHead->value = value;
    return newHead;
}

// returns the original head node
node *append(node *head, int value) {
    if(head != NULL) {
        head->next = append(head->next, value);
        return head;
    }

    node *newTail = malloc(sizeof(node));
    newTail->next = NULL;
    newTail->value = value;

    return newTail;
}

// prints all nodes starting from the head node
void print(node *head, intFunc fn) {
    if(head != NULL) {
        fn(head->value);
        print(head->next, fn);
    }
}

// frees all nodes starting from the head node
void freeList(node *head) {
    if(head != NULL) {
        freeList(head->next);
        free(head);
    }
}