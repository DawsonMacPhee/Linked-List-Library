This is a collection of functions that work together to act as a linked-list data structure.

Functions

    struct Performance *newPerformance()
        Creates a structure holding information about the efficiency of the array.
        
    void push(struct Performance *performance, struct Node **list_ptr, void *src, unsigned int width)
        Adds a node to the begining of the list.
        
    void readHead(struct Performance *performance, struct Node **list_ptr, void *dest, unsigned int width)
        Copies the first element in the list to the dest pointer.
        
    void pop(struct Performance *performance, struct Node **list_ptr, void *dest, unsigned int width)
        Copies the first element in the list to the dest pointer and removes it from the list.
        
    struct Node **next(struct Performance *performance, struct Node **list_ptr)
        Returns a double pointer to the address of the next node in the list.
        
    int isEmpty(struct Performance *performance, struct Node **list_ptr)
        Returns 1 if the given list is empty, otherwise returns 0.
        
    void freeList(struct Performance *performance, struct Node **list_ptr)
        Free all the memory allocated to the linked list.
        
    void readItem(struct Performance *performance, struct Node **list_ptr, unsigned int index, void *dest, unsigned int width)
        Copies an item at a given index into the dest pointer.
        
    void appendItem(struct Performance *performance, struct Node **list_ptr, void *src, unsigned int width)
        Adds an item to the end of the list.
        
    void insertItem(struct Performance *performance, struct Node **list_ptr, unsigned int index, void *src, unsigned int width)
        Inserts an item at a given index into the list.
        
    void prependItem(struct Performance *performance, struct Node **list_ptr, void *src,  unsigned int width)
        Inserts an item to the begining of the list.
        
    void deleteItem(struct Performance *performance, struct Node **list_ptr, unsigned int index)
        Deletes an item at a given index in the list
        
    int findItem(struct Performance *performance, struct Node **list_ptr, int (*compar)(const void *, const void *), void *target, unsigned int width)
        Performs a linear search of the list looking for target and returns it's index.
        Compares using the given compar function pointer.

Files

    list.c
        Contains all the functions in the library
        
    list.h
        Contains all the function declarations for the functions in list.c
    
    test1.c - test3.c
        A collection of main functions to be used to test the linked-list data structure
        
    names3.txt
        Text file containing values to load as linked-lists for testing purposes

Usage (make)

    all
        Compiles all the functions for the library and creates test executables
        
    list.o
        Compiles all the functions in list.c into an object file
        
    test1.o
        Creates object file test1.o
        
    test2.o
        Creates object file test2.o
        
    test3.o
        Creates object file test3.o
        
    test1
        Creates executable test1
        
    test2
        Creates executable test2
        
    test3
        Creates executable test3
        
    clean
        Removes the object files containing the functions
