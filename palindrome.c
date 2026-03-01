#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

char * makeStr (int *strLenght);
void destroyStr (char *str, int strLenght);

// Returns the palindrome status of the deque:
// 0 = palindrome, 1 = not palindrome, 2 = error, 3 = empty deque.
int checksPalindrome (struct deque *d);

int main() {
    struct deque *d;
    int strLenght, i, palindrome;
    char *str;
    
    strLenght = 0;

    if (!(str = makeStr(&strLenght))) {
        return 0;
    }

    if (!(d = makeDeque())) {
        return 0;
    }

    for (i = 0; i < strLenght; i++) {
        if ((pushBack(d, str[i])) == 1) {
            return 0;
        }
    }

    palindrome = checksPalindrome(d);
    if (palindrome == 0) {
        printf("É um palíndromo\n");
    }
    else if (palindrome == 1) {
        printf("Não é um palíndromo\n");
    }
    else if (palindrome == 2) {
        printf("Erro ao consultar palíndromo\n");
    }
    else {
        printf("Palavra não digitada\n\n");
    }

    destroyDeque(d);
    d = NULL;

    destroyStr (str, strLenght);
    str = NULL;

    return 0;
}

char * makeStr (int *strLenght) {
    int i, strSize, maxSize;
    char *str, *tmp;
    char c;
    
    if (!strLenght) {
        return NULL;
    }

    i = 0;
    strSize = 10;
    maxSize = 50;
    
    if (!(str = calloc(1, strSize))) {
        return NULL;
    }

    while (((c = getchar()) != '\n') && (c != EOF)) { // Read user input until newline or end-of-file
        if (i >= strSize -1) { // Need more space
            if (strSize + 10 > maxSize) { // Don't exceed the maximum allowed
            break; 
            }
            strSize +=10; // Increase buffer size by 10
            if (!(tmp = realloc(str, strSize))) { 
                free(str); // Ensure memory allocation succeeded
                return NULL;
            }
            str = tmp;
        }
        str[i] = c; // Store character in array
        i++;
    }
    str[i] = '\0'; // Null-terminate the string

    *strLenght = i; // Store the length of the string

    return str;
}

void destroyStr (char *str, int strLenght) {

    if (!str) {
        return;
    }

    memset(str, 0, strLenght);
    free(str);
}

int checksPalindrome (struct deque *d) {
    int dS, i;
    char first, last;

    if(!d) {
        return 2;
    }

    dS = dequeSize(d);
    if (dS == -1) {
        return 2;
    }
    if (dS == 0) {
        return 3;
    }

    while (dequeSize(d) > 1) { 
        if (((popFront(d, &first)) > 0) || (popBack(d, &last)) > 0) {
            return 2;
        }
        if (first != last) {
            return 1;
        }
    }

    return 0;
}