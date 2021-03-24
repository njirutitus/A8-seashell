// A module for decoding integers into @ pictures

// SEASHELL_READONLY

// at_decode(data, len) converts a sequence of integers into an @ picture
//   and returns a new string containing the picture
//   [see assignment(s) for details]
// note: returns a new string
// requires: data is a valid int array (not NULL)
//           data has len elements [not asserted]
//           len > 0
// effects: allocates memory (caller must free)
// time: O(n), where n is the number of chars in the picture
char *at_decode(const int data[], int len);
