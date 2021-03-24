// A module for encoding @ pictures into integers

// SEASHELL_READONLY

// at_encode(picture, len) converts a picture made up of:
//   '@', ' ' and newlines ('\n') and converts it to a sequence
//   of integers [see assignment(s) for details]
// note: returns a new array of integers and modifies *len
//         to store the length of the new array
//       if picture is an empty string, it returns NULL
//         and *len is modified to be zero
//       contiguous characters ('@' or ' ') must be grouped 
//         together to generate the fewest number of integers (see A3)
// requires: picture is a valid string (not NULL)
//           len is a valid pointer (not NULL)
// effects: modifies *len
//          allocates memory (caller must free)
// time: O(n), where n is the number of chars in the picture
int *at_encode(const char *picture, int *len);
