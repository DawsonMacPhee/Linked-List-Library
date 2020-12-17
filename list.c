#ifndef __stdio_h_
#include <stdio.h>
#endif

#ifndef __string_h_
#include <string.h>
#endif

#ifndef __stdlib_h_
#include <stdlib.h>
#endif

#ifndef __list_h_
#include "list.h"
#endif

// Allocates memory for the struct 'Performance' and initializes its values
struct Performance *newPerformance(){
    struct Performance *performance = malloc(sizeof(struct Performance));
    if(performance == NULL){
        fprintf(stderr, "The allocation of memory for the Performance Struct has failed\n");
        exit(1);
    }
    performance -> reads = 0;
    performance -> writes = 0;
    performance -> mallocs = 0;
    performance -> frees = 0;
    return performance;
}

// Allocates memory and adds a new node to the begining of a list
void push(struct Performance *performance, struct Node **list_ptr, void *src, unsigned int width){
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        fprintf(stderr, "push: the new node could not be malloced\n");
        free(performance);
        exit(1);
    }
    newNode -> data = malloc(width);
    if(newNode -> data == NULL){
        fprintf(stderr, "push: the data pointer within the new node could not be malloced\n");
        free(newNode);
        free(performance);
        exit(1);
    }
    memcpy(newNode -> data, src, width);
    newNode -> next = *list_ptr;
    *list_ptr = newNode;
    performance -> mallocs += 1;
    performance -> writes += 1;
}

// Reads the first element in a list
void readHead(struct Performance *performance, struct Node **list_ptr, void *dest, unsigned int width){
    if(isEmpty(performance, list_ptr)){
        fprintf(stderr, "readHead: the given list is empty\n");
        free(performance);
        exit(1);
    }
    memcpy(dest, (*list_ptr) -> data, width);
    performance -> reads += 1;
}

// Removes the first element in a list
void pop(struct Performance *performance, struct Node **list_ptr, void *dest, unsigned int width){
    if(isEmpty(performance, list_ptr)){
        fprintf(stderr, "pop: the given list is empty\n");
        free(performance);
        exit(1);
    }
    readHead(performance, list_ptr, dest, width);
    struct Node *destroyNode = *list_ptr;
    *list_ptr = (*list_ptr) -> next;
    free(destroyNode -> data);
    free(destroyNode);
    performance -> frees += 1;
}

// Returns a malloced double pointer that points to the next item in a list
struct Node **next(struct Performance *performance, struct Node **list_ptr){
    if(isEmpty(performance, list_ptr)){
        fprintf(stderr, "next: the given list is empty\n");
        free(performance);
        exit(1);
    }
    performance -> reads += 1;
    return &((*list_ptr) -> next);
}

// Returns 1 if the given list is empty, otherwise returns 0
int isEmpty(struct Performance *performance, struct Node **list_ptr){
    if(list_ptr == NULL || *list_ptr == NULL){
        return 1;
    }
    return 0;
}

// Frees the contents of a list via the pop function
void freeList(struct Performance *performance, struct Node **list_ptr){
    void *temp = NULL;
    while((*list_ptr) != NULL){
        pop(performance, list_ptr, temp, 0);
    }
}

// Reads an item at the given index of a list
void readItem(struct Performance *performance, struct Node **list_ptr, unsigned int index, void *dest, unsigned int width){
    for(int i = 0; i < index; i++){
        list_ptr = next(performance, list_ptr);
    }
    readHead(performance, list_ptr, dest, width);
}

// Adds an item to the end of a list
void appendItem(struct Performance *performance, struct Node **list_ptr, void *src, unsigned int width){
    while(!isEmpty(performance, list_ptr)){
        list_ptr = next(performance, list_ptr);
    }
    push(performance, list_ptr, src, width);
}

// Inserts a new items at a given index in a list
void insertItem(struct Performance *performance, struct Node **list_ptr, unsigned int index, void *src, unsigned int width){
    for(int i = 0; i < index; i++){
        list_ptr = next(performance, list_ptr);
    }
    push(performance, list_ptr, src, width);
}

// Adds an item to the beginning of a list
void prependItem(struct Performance *performance, struct Node **list_ptr, void *src, unsigned int width){
    insertItem(performance, list_ptr, 0, src, width);
}

// Deletes an item at a given index in a list
void deleteItem(struct Performance *performance, struct Node **list_ptr, unsigned int index){
    void *dest = NULL;

    for(int i = 0; i < index; i++){
        list_ptr = next(performance, list_ptr);
    }
    pop(performance, list_ptr, dest, 0);
}

// Finds an item in a list and returns it's index
// If the item does not exist, it returns -1
int findItem(struct Performance *performance, struct Node **list_ptr, int (*compar)(const void *, const void *), void *target, unsigned int width){
    int index = 0;
    void *dest = malloc(width);

    while(!isEmpty(performance, list_ptr)){
        readHead(performance, list_ptr, dest, width);
        if((*compar)(dest, target) == 0){
            free(dest);
            return index;
        }
        list_ptr = next(performance, list_ptr);
        index += 1;
    }
    free(dest);
    return -1;
}

