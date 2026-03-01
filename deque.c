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
