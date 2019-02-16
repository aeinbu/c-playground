#include <stdlib.h>
#include <stdio.h>

#ifndef NODE_H
#define NODE_H
struct node {
    struct node *next;
    int value;
};

typedef void (*intFunc)(int);

// returns the new head node
struct node *prepend(struct node *head, int value);

// returns the original head node
struct node *append(struct node *head, int value);

// prints all nodes starting from the head node
void print(struct node *head, intFunc action);

// frees all nodes starting from the head node
void freeList(struct node *head);

#endif