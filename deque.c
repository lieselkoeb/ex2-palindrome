// Internal deque implementation used by the palindrome program.
// Provides a doubly linked deque storing characters.

// INCLUDES ----------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

// FOWARD DECLARATIONS ----------------------

// Node of the deque (internal structure)
struct deque_n;

// Creates and returns an empty deque node.
// Returns NULL if memory allocation fails.
struct deque_n *makeDequeNode();

// Prints the contents of the node.
void dequeNodePrint(struct deque_n *n);

// Frees the given node.
// After this call, the node pointer must not be used anymore.
void destroyDequeNode(struct deque_n *n);

// TYPE DEFINITIONS ----------------------

struct deque {
    struct deque_n * beg; // begginig
    struct deque_n * end; // ending
    int size;
};

struct deque_n {
    struct deque_n * next; // next
    struct deque_n * prev; // previous
    char c; // character
};

// INTERNAL HELPERS ----------------------

struct deque_n *makeDequeNode() {
    struct deque_n *n;
    
    if (!(n = calloc(1, sizeof(struct deque_n)))) {
        return NULL;
    }

    return n;
}

void dequeNodePrint(struct deque_n *n) {
    if (!n) {
        return;
    }

    printf("%c", n->c);

    if (n->next != NULL) {
        printf(" | ");
    }
}

void destroyDequeNode(struct deque_n *n) {
    if (!n) {
        return;
    }

    memset(n, 0, sizeof(struct deque_n));

    free(n);
}


// PUBLIC FUNCTION IMPLEMENTATIONS ----------------------

struct deque *makeDeque() {
    struct deque *d;

    if (!(d = calloc(1, sizeof(struct deque)))) {
        return NULL;
    }

    return d;
}

int pushFront(struct deque *d, char c) {
    struct deque_n *n;

    if (!d) {
        return 1;
    }

    if (!(n = makeDequeNode())) {
        return 1;
    }

    n->c = c; // Store character in the node

    if (d->size == 0) { // EMPTY DEQUE
        d->end = n; // Ending now points to the new node
    }
    else { // DEQUE NOT EMPTY
        n->next = d->beg; // New node points to the former begginig
        d->beg->prev = n; // Former beggining points back to the new node
    }

    d->beg = n; // Beggining now points to the new node
    d->size++; // Increase deque size

    return 0;
}

int pushBack(struct deque *d, char c) {
    struct deque_n *n;

    if (!d) {
        return 1;
    }

    if (!(n = makeDequeNode())) {
        return 1;
    }

    n->c = c; // Store character in the node

    if (d->size == 0) { // EMPTY DEQUE
        d->beg = n; // Begginig now points to the new node
    }
    else { // DEQUE NOT EMPTY
        n->prev = d->end; // New node points back to the former ending
        d->end->next = n; // Former ending points to the new node
    }

    d->end = n; // Ending now points to the new node
    d->size++; // Increase deque size

    return 0;
}

// Removes the character at the front of the deque and stores it in *c.
// Frees the removed node to prevent memory leaks.
// Returns 0 on success.
// Returns 1 if an error occurs.
// Returns 2 if the deque is empty.
int popFront(struct deque *d, char *c) {
    struct deque_n *n;

    if ((!d) || (!c)) {
        return 1;
    }

    if (d->size == 0) { // DEQUE IS EMPTY
        return 2;
    }

    n = d->beg; // Store the popped node
    *c = n->c; // Store the character from the popped node in *c

    if (d->size == 1) { // DEQUE HAS ONLY 1 NODE
        d->beg = NULL;
        d->end = NULL;
    }
    else { // DEQUE HAS MORE THAN 1 NODE
        d->beg = n->next; // Update the beginning of the deque
        d->beg->prev = NULL; // Set the previous pointer of the new beginning to NULL
    }

    d->size--; // Decrease deque size

    destroyDequeNode(n);

    return 0;
}

int dequeSize(struct deque *d) {
    if (!d) {
        return -1;
    }

    return d->size;
}

void dequePrint(struct deque *d) {
    struct deque_n *n;
    
    if (!d) {
        return;
    }

    if (d->size == 0) {
        printf("DEQUE VAZIO\n");
        return;
    }

    printf("TAMANHO: %d\n", d->size);

    n = d->beg;
    while (n != NULL) {
        dequeNodePrint(n);
        n = n->next;
    }
    printf("\n");

    return;
}
