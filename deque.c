// Internal deque implementation used by the palindrome program.
// Provides a doubly linked deque storing characters.

// INCLUDES ----------------------

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// FOWARD DECLARATIONS ----------------------

// Node of the deque (internal structure)
struct deque_n;

// Creates and returns an empty deque node.
// Returns NULL if memory allocation fails.
struct deque_n *makeDequeNode();

// Prints the contents of the node.
void dequeNodePrint(struct deque_n *n);

// TYPE DEFINITIONS ----------------------

struct deque {
    struct deque_n * b; // begginig
    struct deque_n * e; // ending
    int size;
};

struct deque_n {
    struct deque_n * n; // next
    struct deque_n * p; // previous
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

    if (n->n != NULL) {
        printf(" | ");
    }
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
        d->e = n; // Ending now points to the new node
    }
    else { // DEQUE NOT EMPTY
        n->n = d->b; // New node points to the former begginig
        d->b->p = n; // Former beggining points back to the new node
    }

    d->b = n; // Beggining now points to the new node
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
        d->b = n; // Begginig now points to the new node
    }
    else { // DEQUE NOT EMPTY
        n->p = d->e; // New node points back to the former ending
        d->e->n = n; // Former ending points to the new node
    }

    d->e = n; // Ending now points to the new node
    d->size++; // Increase deque size

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

    n = d->b;
    while (n != NULL) {
        dequeNodePrint(n);
        n = n->n;
    }
    printf("\n");

    return;
}
