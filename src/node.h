#include <stdlib.h>
#include <stdio.h>

#ifndef NODE_H
#define NODE_H

typedef struct node {
    struct node *next;
    int value;
} node;

typedef void (*intFunc)(int);

// returns the new head node
node *prepend(node *head, int value);

// returns the original head node
node *append(node *head, int value);

// prints all nodes starting from the head node
void print(node *head, intFunc action);

// frees all nodes starting from the head node
void freeList(node *head);

#endif