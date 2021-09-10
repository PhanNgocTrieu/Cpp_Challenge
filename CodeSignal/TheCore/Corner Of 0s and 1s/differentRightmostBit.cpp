// Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
// You're given two integers, n and m. Find position of the rightmost bit in which they differ in their binary representations (it is guaranteed that such a bit exists), counting from right to left.

// Return the value of 2^position_of_the_found_bit (0-based).

// Example

// For n = 11 and m = 13, the output should be
// differentRightmostBit(n, m) = 2.

// 1110 = 10112, 1310 = 11012, the rightmost bit in which they differ is the bit at position 1 (0-based) from the right in the binary representations.
// So the answer is 2^1 = 2.

// For n = 7 and m = 23, the output should be
// differentRightmostBit(n, m) = 16.

// 710 = 1112, 2310 = 101112, i.e.

// 00111
// 10111
// So the answer is 2^4 = 16.

#include <iostream>
#include <math.h>

int differentRightmostBit(int n, int m) {
  return pow(2,log2((m^n) & -(m^n)));
}


int main()
{
    std::cout << differentRightmostBit(7,23);
    return 0;
}