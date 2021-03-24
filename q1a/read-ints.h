// A simple module that provides the read_ints function

// SEASHELL_READONLY

// read_ints(len) reads in all ints from I/O (until fail or EOF)
//   and returns a new dynamically allocated array with those ints
//   or NULL if no ints were read in
// note: updates *len to contain the len of the new array
//       (which will be 0 if this function returns NULL)
// requires: len is a valid pointer (not NULL)
// effects: reads input
//          modifies *len
//          may allocate memory (caller must free)
// time: O(n), where n is the len of the array
int *read_ints(int *len);
