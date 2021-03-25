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
#include "biggie.h"
#include <strings.h>

int main() {
  struct biggie *big = biggie_create("986321");
  struct biggie *big1 = biggie_create("344321");
  biggie_add(big,big1);
  biggie_print(big,true);
  biggie_destroy(big);
  biggie_destroy(big1);
  return 0;
}

////////////////////////////////////////////////////////////////////////
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
  struct biggie *big = malloc(sizeof(struct biggie));
  // char *str = s;
  int len = strlen(s);

  // check if it contains non digit characters
  for (int i = 0; i < len; i++) {
    if (i == 0 && s[i] == '-') continue;
    if (s[i] < 48 || s[i] > 57 ) {
        return NULL;
    }
  }

  // check if is not negative and contains a leading zero
  if (s[0] != '-' && s[0] == '0' && len > 1 ) {
    return NULL;
  }

  // check if negative and contains a leading zero
  if (s[0] == '-' && s[1] == '0') {
    return NULL;
  }

  // check if empty
  if(len < 1) return NULL;
  
  if (s[0] == '-') {
    big->negative = true;
    big->digits = malloc(len-1*sizeof(char));
    for (int i = 1; i < len; i++) {
      big->digits[i-1] = s[len-i];
    }
  }  
  else {
    big->negative = false;
    big->digits = malloc(len*sizeof(char));
    for (int i = 0; i < len; i++) {
      big->digits[i] = s[len-i-1];
    }
  }

  return big;

}

void biggie_destroy(struct biggie *big) {
  free(big->digits);
  free(big);
}

// biggie_print() prints the biggie to output followed by
//   an optional newline (trailing \n is printed if newline is true)
// effects: prints output
// time: O(logn)
void biggie_print(const struct biggie *big, bool newline) {
  if (newline) {
    printf("%s\n",big->digits);
  }
  else {
    printf("%s",big->digits);
  }  
}

void biggie_add(struct biggie *n, const struct biggie *m) {
  int lenn = strlen(n->digits);
  int lenm = strlen(m->digits);
  int max_length = lenn > lenm ? lenn : lenm;
  int carry = 0;
  int sum = 0;
  int digit;
  
  if (max_length > lenn) n->digits = realloc(n->digits, max_length * sizeof(char *));

  for ( int i = 0 ; i < max_length ; i++) {
    if ( lenn >= i && lenm >= i)
      sum = (n->digits[i] - '0') + (m->digits[i] - '0');
    else if (lenm >= i) 
      sum = m->digits[i] - '0';
    else
       sum = n->digits[i] - '0';
    sum = sum + carry;
    digit = sum % 10;
    carry = ( sum - carry ) / 10;
    n->digits[i] = digit + '0';
  }

  if (carry > 0) {
    n->digits[max_length] = carry + '0';
  }

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
