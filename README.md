# Palindrome Checker Using Deque

This project implements a **palindrome checker** in C using a **deque** (double-ended queue).  
It was developed as an exercise for **Programming 2** (UFPR).

---

## Files

- **`deque.h` / `deque.c`** – Implementation of a double-ended queue:
  - Create, destroy, push/pop front and back
  - Check size, print contents
  - Handles memory and reports errors
- **`palindrome.c`** – Program that:
  - Reads a string from standard input
  - Stores it in a deque
  - Checks if the string is a palindrome
  - Prints the result

---

## Features

- Safe dynamic memory allocation
- Maximum input length: 50 characters
- Handles errors and empty input
- Modular design: deque is separated from palindrome logic

---

## Usage

1. Compile:

```bash
gcc -o palindrome palindrome.c deque.c
```

2. Run the program:

```bash
./palindrome
```

3. Example:
```Plain text
Input: radar
Output: É um palíndromo

Input: hello
Output: Não é um palíndromo
```

---

## Notes
- The deque implementation is internal, not intended as a public library.
- All memory allocations are checked to avoid crashes.
- The program demonstrates use of a deque for algorithmic problem solving in C.

---

## Author
**Liesel Koeb** – Cruzeiro do Sul  
Exercise for **Programming 2** (UFPR)
