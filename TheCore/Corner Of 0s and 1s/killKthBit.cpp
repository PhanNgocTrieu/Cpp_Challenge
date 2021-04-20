// Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
// In order to stop the Mad Coder evil genius you need to decipher the encrypted message he sent to his minions.
// The message contains several numbers that, when typed into a supercomputer,
// will launch a missile into the sky blocking out the sun, and making all the people on Earth grumpy and sad.

// You figured out that some numbers have a modified single digit in their binary representation.
// More specifically, in the given number n the kth bit from the right was initially set to 0,
// but its current value might be different. It's now up to you to write a function that will change the kth bit of n back to 0.

// Example

// For n = 37 and k = 3, the output should be
// killKthBit(n, k) = 33.

// 3710 = 1001012 ~> 1000012 = 3310.

// For n = 37 and k = 4, the output should be
// killKthBit(n, k) = 37.

// The 4th bit is 0 already (looks like the Mad Coder forgot to encrypt this number), so the answer is still 37.


/*
Algorithm:
- Example: we have n = 30 ==> n_bit = 11110 and k-th = 3
- we have to put the position that we wanna change equal to 1 => 1 << (k-th - 1):
  1 = 00001 => 1 << (k-th - 1) = 2  == 00100
- Reverse bit of (k_th - 1) => 00100-> 11011
- Using AND logic to change value of k_th
  11110                     1 & 1 = 1   <==> 0 & 0 = 1
 &                          1 & 0 = 0   <==> 0 & 1 = 0
  11011
 -------
  11010 
*/

#include <iostream>


int killKthBit(int n, int k) {
  return n & ~(1 << (k - 1));
}

int main()
{
  return 0;
}