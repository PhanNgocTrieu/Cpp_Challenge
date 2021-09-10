// Consider integer numbers from 0 to n - 1 written down along the circle in such a way 
// That the distance between any two neighboring numbers is equal (note that 0 and n - 1 are neighboring, too).

// Given n and firstNumber, find the number which is written in the radially opposite position to firstNumber.

// Example:
// For n = 10 and firstNumber = 2, the output should be
// circleOfNumbers(n, firstNumber) = 7.
#include <iostream>

int circleOfNumbers(int n, int firstNumber) {
    int haf = n / 2;
    if (firstNumber < haf)
        return firstNumber + haf;
    return firstNumber - haf;
}

int main()
{
    std::cout << circleOfNumbers(10,7);
    return 0;
}