#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    int length = strlen(s);
    int back = -1;
    char *s1 = s;
    
    while(*s) {
        char *s2 = s;

        if(*s == ')' || *s == ']' || *s == '}') {
            back += 2;
            if(s2 > s1) s2 -= back;

            if(
                (*s2 != '(' && *s == ')') ||
                (*s2 != '[' && *s == ']') ||
                (*s2 != '{' && *s == '}')
            ) {
                return false;
            }
        } else {
            if(back > -1) back = -1;
        }

        s++;
    }

    return true;
}