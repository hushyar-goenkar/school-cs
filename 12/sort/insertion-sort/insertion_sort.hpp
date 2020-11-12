// INSERTION SORT
/**
 * Deck Of Cards Analogy:
 * You have an unsorted deck of cards
 * You want to sort these cards according to the number on the card
 * 1) Pick the first card and keep it separate
 * 2) Pick the next card and place it after or before the separate card
 * 3) Pick the next card and place it with the two separate cards such that the
 * separate stack of cards is always sorted
 * 4) Continue this process until the separate stack becomes a completely sorted deck.
 *
 * Programmatically doing:
 * 1) Divide the array into two parts, the left side and right side.
 * 2) Initially, the left side will only consist of one element ie the first elem
 * - One elem is always sorted
 * 3) Start traversing the array
 * - Take the 2nd elem and insert it either before or after the 1st elem
 * - Take the next elem in the not sorted part and insert it in the right place in the sorted part
 * - Do this by shifting the elements until you find the right place, then place it there
 * - Similar to bubbling an element, just backwards.
 * 4) Continue this process until you get an aray with only sorted part
 *
 * Time Complexity:
 * Best (array already sorted) - O(n)
 * Worst (large unsorted arrays) - O(n^2)
 * Practical only for small arrays
 */

int* insertion_sort(int n, int a[]) {
  int i, temp, j;

  for (i = 1; i < n; i++) {
    temp = a[i]; // Store the current elem, from the unsorted part of the array.

    for (j = i - 1; (j >= 0) && (a[j] > temp); j--) {
      a[j+1] = a[j]; // Shift each element of sorted part to the right by one, until the element is smaller than temp
    }
    a[j+1] = temp; // Here a[j] is smaller than temp and a[j+1] has already been shifted to a[j+2]; Insert temp here.
  }

  return a;
}
