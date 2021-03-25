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
#include "triple-s.h"
#include <string.h>
#include <assert.h>

void merge_sort( char *a[], int len);
void merge(char *dest[], const char *src1[], int len1, const char *src2[], int len2);

int main() {
    struct triple_s *sss = sss_create();
    sss_destroy(sss);
    
}

struct triple_s{
    int len;
    int maxlen;
    char **aos;
};

// The following applies to all functions
// requires: all sss parameters are valid (not NULL) 
//           all s parameters are valid (not NULL)
// time: (n) is the number of strings in the sss
//       (m) is the length of the string s

// sss_create() creates a new SSS ADT
// effects: allocates memory (you must call sss_destroy)
// time: O(1)

struct triple_s *sss_create(void){
    struct triple_s *sss = malloc(sizeof(struct triple_s));
    sss->len = 0;
    sss->maxlen = 1;
    sss->aos = malloc(sss->maxlen * sizeof(char *));
    return sss;
}

// sss_destroy(sss) destroys sss
// requires: sss is valid (not NULL)
// effects: sss is no longer valid
// time: O(n)
void sss_destroy(struct triple_s *sss) {
    free(sss->aos);
    free(sss);
}

// sss_add(sss, s) adds s to sss in the correct index (lexicographically)
// notes: if s already exists, there is no effect
//        when s is added, the indices of words that lexicographically
//          follow s will be changed (+1) because s is added into the "middle"
// effects: may modify sss
// time: O(n + m*logn)
void sss_add(struct triple_s *sss, const char *s) {
    assert(sss);
    if (sss->len == sss->maxlen) {
        sss->maxlen *= 2;
        sss->aos = realloc(sss->aos, sss->maxlen * sizeof(char *));
    }
    strcpy(sss->aos[sss->len] , s);
    merge_sort(sss->aos,sss->len);
    sss->len += 1;
}

// sss_add_follows(sss, s) adds s to the "end" of the sss
// requires: s lexicographically follows all strings already in sss
// effects: modifies sss
// time: O(m) [amortized]
void sss_add_follows(struct triple_s *sss, const char *s) {
    assert(sss);
    if (sss->len == sss->maxlen) {
        sss->maxlen *= 2;
        sss->aos = realloc(sss->aos, sss->maxlen * sizeof(char *));
    }
    strcpy(sss->aos[sss->len] , s);
    sss->len += 1;
}

// sss_remove(sss, s) removes s from sss (if it exists)
// notes: if s is removed, the indices of words that lexicographically
//          follow s will be changed (-1)
// effects: may modify sss
// time: O(n + m*logn)
void sss_remove(struct triple_s *sss, const char *s) {
    assert(sss);
    assert(sss->len);
    int len = sss->len;
    struct triple_s *temp = sss;
    char *str;
    strcpy(str,s);
    int count = 0;
    for (int i = 0 ; i <= len; i++) {
        if ( strcmp(sss->aos[i],str) != 0) {
            count++;
            temp->aos = realloc(temp->aos, count * sizeof(char *));
            temp->aos[count] = sss->aos[i];
        }

    }
    sss = temp;
    
}

// sss_count(sss) gets the number of strings in sss
// time: O(1)
int sss_count(const struct triple_s *sss) {
    int count = sizeof(sss->aos)/sizeof(char *);
    return count;

}

// sss_search(sss, s) finds the index of s in sss
// note: returns -1 if s does not appear in the sss
// time: O(m*logn)
int sss_search(const struct triple_s *sss, const char *s) {
    assert(sss);
    assert(sss->len);
    int len = sss->len;
    for (int i = 0 ; i <= len; i++) {
        if ( strcmp(sss->aos[i],s) == 0) {
            return i;
        }

    }

    return -1;
    
}

// sss_get(sss, idx) retrieves a pointer to the string in sss
//   at the given idx (index)
// requires: 0 <= idx < sss_count(sss)
// time: O(1)
const char *sss_get(const struct triple_s *sss, int idx) {
    char *s;
    s = &sss->aos[idx];
    return s;
}

// merge(dest, src1, len1, src2, len2) modifies dest to contain
// the elements from both src1 and src2 in sorted order
// requires: length of dest is at least (len1 + len2)
// src1 and src2 are sorted [not asserted]
// effects: modifies dest
// time: O(n), where n is len1 + len2
void merge(char **dest, const char **src1, int len1,
    const char **src2, int len2) {
    int pos1 = 0;
    int pos2 = 0;
    for (int i = 0; i < len1 + len2; ++i) {
        if (pos1 == len1 || (pos2 < len2 && strcmp(src2[pos2],src1[pos1]) < 0)) {
            strcpy(dest[i] , src2[pos2]);
            ++pos2;
        } else {
            strcpy(dest[i] , src1[pos1]);
            ++pos1;
        }
    }
}



void merge_sort( char **a, int len) {
    if (len <= 1) return;
    int llen = len / 2;
    int rlen = len - llen;
    char **left = malloc(llen * sizeof(char *));
    char **right = malloc(rlen * sizeof(char *));
    for (int i = 0; i < llen; ++i) strcpy(left[i], a[i]);
    for (int i = 0; i < rlen; ++i) strcpy(right[i] , a[i + llen]);
    merge_sort(left, llen);
    merge_sort(right, rlen);
    merge(a, (const char **)left, llen, (const char **)right, rlen);
    free(left);
    free(right);
}


