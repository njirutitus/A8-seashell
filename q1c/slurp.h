// A module for reading all input as a string

// slurp() reads in all input until EOF and returns a new string 
//   with the contents (or NULL if EOF is encountered immediately)
// effects: may allocate memory (caller must free)
// time:    O(n) [amortized]
char *slurp(void);
