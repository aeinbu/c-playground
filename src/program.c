#include <stdio.h>
#include <stdlib.h>
#include "node.h"


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

    return -1;
}