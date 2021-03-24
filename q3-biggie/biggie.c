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

#include <stdlib.h>
#include "biggie.h"

/////////////////////////////////////////////////////////////////////////////
// DO NOT CHANGE THIS STRUCTURE
/////////////////////////////////////////////////////////////////////////////
struct biggie {
  bool negative;
  char *digits;
};
// notes: digits is a properly null-terminated dynamic string
//        digits contains the number reversed, so 1203 => "3021"
//        digits cannot have leading zeros, so 1203 cannot be "30210"
//        zero is stored as "0" and cannot be negative (negative is false)
/////////////////////////////////////////////////////////////////////////////

struct biggie *biggie_create(const char *s) {
  return NULL; // dummy value
}

void biggie_destroy(struct biggie *big) {
}

void biggie_print(const struct biggie *big, bool newline) {
}

void biggie_add(struct biggie *n, const struct biggie *m) {
}

void biggie_sub(struct biggie *n, const struct biggie *m) {
}

void biggie_mult(struct biggie *n, const struct biggie *m) {
}

bool biggie_eq(const struct biggie *n, const struct biggie *m) {
  return false; // dummy value
}

bool biggie_gt(const struct biggie *n, const struct biggie *m) {
  return true; // dummy value
}

struct biggie *biggie_copy(const struct biggie *n) {
  return NULL; // dummy value
}

/////////////////////////////////////////////////////////////////////////////
// BONUS:
/////////////////////////////////////////////////////////////////////////////

void biggie_div(struct biggie *n, const struct biggie *m) {
}
