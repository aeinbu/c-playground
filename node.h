#include <stdlib.h>
#include <stdio.h>

#ifndef NODE_H
#define NODE_H
struct node {
    struct node *next;
    int value;
};

// returns the new head node
struct node *prepend(struct node *head, int value);

// returns the original head node
struct node *append(struct node *head, int value);

// prints all nodes starting from the head node
void print(struct node *head);

// frees all nodes starting from the head node
void freeList(struct node *head);

#endif