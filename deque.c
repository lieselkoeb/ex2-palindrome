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

// PUBLIC FUNCTION IMPLEMENTATIONS ----------------------

struct deque *makeDeque() {
    struct deque *d;

    if (!(d = malloc(sizeof(struct deque)))) {
        return NULL;
    }

    memset(d, 0, sizeof(struct deque));

    return d;
}
