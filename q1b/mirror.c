///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 
 
// ERROR_NO_INTEGRITY_STATEMENT 
//  
// Name: ERROR_NO_NAME 
// login ID: ERROR_NO_LOGIN 
///////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mirror.h"

int main() {
    char *m = mirror("Hello");
    printf("%s",m);
    free(m);
}
char *mirror(const char *str) {
    int len = strlen(str);
    char *s;
    strcpy(s,str);
    char *m = malloc(len*2*sizeof(char));
    strcpy(m,s);
    strcat(m,strrev(s));
    return m;
}