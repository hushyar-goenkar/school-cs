// MERGE SORT

/**
 * NOTE: This is a recursive algorithm
 *
 * Assume we have two sorted arrays A and B
 * We can combine these two to get a larger completely sorted array C
 * Procedure:
 * 1) Compare the first elements of each sorted array and place the smallest in array C.
 * 2) Compare the next elements and place the smallest one in array C.
 * 3) Continue the process until one of the input arrays is completely exhausted.
 * 4) Place all the elements of the remaining array at the end of array C.
 *
 * To sort an array:
 * 1) A big array can be divided into two arrays of half the size.
 * 2) These smaller arrays can be recursively sorted and then merged.
 * 3) These smaller arrays can be recursively divided and then merged and so on.
 *
 * Time Complexity:
 * worst/avg - O(nlogn)
 */

/**
 * @param a First array
 * @param nA Size of first array
 * @param b Second array
 * @param B Size of second array
 * @param c Third array pointer to place the final sorted array in
 */
int* merge(int* a, int nA, int* b, int nB, int* c) {
  int i, // Iterate through final array c
  iA = 0, // Iterate through A
  iB = 0; // Iterate through B

  for (i = 0; i < nA + nB; i++) {
    if (iA < nA && iB < nB) { // Make sure that everything is in bounds
      if (a[iA] < b[iB]) c[i] = a[iA++]; // Place the smaller among a[iA] and b[iB] in c[i];
      else c[i] = b[iB++];
    }
    else if (iA < nA) c[i] = a[iA++]; // In this zone, one of a and b is out of bounds
    else if (iB < nB) c[i] = b[iB++]; // Whichever is in bounds, place it in c[i]
  }

  return c;
}

/**
 * @param a Array to be sorted
 * @param offset The index of the element from where the array is to be sorted. eg: offset = 1 means that all elements from index 1 till the end will be sorted
 * @param nA size of array a
 * @param c Pointer to the final array where the sorted array will be placed. Size = nA - offset.
 */
int* merge_sort(int* a, int offset, int nA, int* c) {
  if (nA > 1) { // If the array is of length 1 then it is already sorted -_-
    int n1 = nA / 2, // NOTE: n1 is the floor(nA/2) because n1 is an integer and it will truncate
      n2 = nA - n1, // Array of size nA has been split into two arrays of size n1 and n2 which are approximately of same size.
      t1[n1], // Define the two new smaller arrays
      t2[n2]; // This is where the final sorted array will be stored

    return merge( // Recursicvely merge the two smaller sorted arrays
      merge_sort(a, offset, n1, t1), // Sort from offset to n1 (offset will be 0 in the first step)
      n1,
      merge_sort(a, offset + n1, n2, t2), // Sort from offset + n1 to n2 and return it after storing in t2
      n2,
      c // Merge and store in final c
    );
  }
  else {
    c[0] = a[offset]; // Recursion exit condition
    return c;
  }
}
