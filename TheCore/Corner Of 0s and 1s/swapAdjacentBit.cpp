// Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
// You're given an arbitrary 32-bit integer n. Take its binary representation,
// split bits into it in pairs (bit number 0 and 1, bit number 2 and 3, etc.) and swap bits in each pair.
// Then return the result as a decimal number.

// Example

// For n = 13, the output should be
// swapAdjacentBits(n) = 14.

// 1310 = 11012 ~> {11}{01}2 ~> 11102 = 1410.

// For n = 74, the output should be
// swapAdjacentBits(n) = 133.

// 7410 = 010010102 ~> {01}{00}{10}{10}2 ~> 100001012 = 13310.
// Note the preceding zero written in front of the initial number: since both numbers are 32-bit integers,
// they have 32 bits in their binary representation. The preceding zeros in other cases don't matter,
// so they are omitted. Here, however, it does make a difference.


/*
Solution

((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)

Explanation

Let’s take n = 13, for example.
1310 = 11012

(11012 & 10102) >> 1 extracts the higher bits and shifts to the lower bit position.

11012 & 10102 = 10002
10002 >> 1 = 01002
(11012 & 01012) << 1 extracts the lower bits and shifts to the higher bit position.

11012 & 01012 = 01012
01012 << 1 = 10102
So, we combine the two, and we get our swapped bits.

01002 | 10102 = 11102
*/
#include <iostream>

// 0xAAAAAAAA: even bits
// 0x55555555: odd bits
int swapAdjacentBits(int n) {
    return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}


int main()
{
    std::cout << swapAdjacentBits(1);
    return 0;
}