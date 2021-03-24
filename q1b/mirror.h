// A simple "Mirror" module

// SEASHELL_READONLY

// mirror(str) returns a new string that is the "mirror" of str,
//   which is str followed by str reversed
// example: "Mirror" => "MirrorrorriM"
// requires: str is a valid string (not NULL pointer)
// effects:  allocates memory (caller must free)
// time: O(n)
char *mirror(const char *str);
