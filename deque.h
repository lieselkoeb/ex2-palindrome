// Internal deque implementation used by the palindrome program.
// Not intended as a public library API.

#ifndef DEQUE
#define DEQUE

struct deque;

// Creates and returns an empty deque.
// Returns NULL if memory allocation fails.
struct deque *makeDeque();

// Frees all memory used by the deque, including all nodes.
// After this call, the deque pointer must not be used anymore.
void destroyDeque(struct deque *d);

// Inserts a character at the front (beginning) of the deque.
// Returns 0 on success, 1 on failure.
int push_front(struct deque *d, char c);

// Inserts a character at the back (end) of the deque.
// Returns 0 on success, 1 on failure.
int push_back(struct deque *d, char c);

// Removes the character at the front of the deque and stores it in *c.
// Returns 0 on success.
// Returns 1 if the deque is empty or an error occurs.
int pop_front(struct deque *d, char *c);

// Removes the character at the back of the deque and stores it in *c.
// Returns 0 on success.
// Returns 1 if the deque is empty or an error occurs.
int pop_back(struct deque *d, char *c);

// Returns the number of elements currently stored in the deque.
// Returns -1 if an error occurs.
int dequeSize(struct deque *d);

// Prints the contents of the deque from front to back.
void dequePrint(struct deque *d);

#endif