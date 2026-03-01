#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

char * makeStr (int *strLenght);
void destroyStr (char *str, int strLenght);

int main() {
    struct deque *d;
    int strLenght, i;
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