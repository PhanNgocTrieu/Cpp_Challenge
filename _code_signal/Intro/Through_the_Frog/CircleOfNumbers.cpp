//Consider integer numbers from 0 to n - 1 written down along the circle in such a way
//that the distance between any two neighboring numbers is equal 
//(note that 0 and n - 1 are neighboring, too).
//
//Given n and firstNumber, 
//find the number which is written in the radially opposite position to firstNumber.
//
//Example
//
//For n = 10 and firstNumber = 2, the output should be
//circleOfNumbers(n, firstNumber) = 7.

#include <iostream>
#include <time.h>

int circleOfNumbers(int n, int firstNumber) {
    if (firstNumber < n / 2)
        return n / 2 + firstNumber;
    return firstNumber - n / 2;
}


int main()
{
    int numbers[50];
    int position[50];

    for (int i = 0; i < 50; i++)
    {
        numbers[i] = rand() % 20 + 4;
        position[i] = rand() % numbers[i] + 0;
        std::cout << "#Test case " << i << ": numbers - " << numbers[i]
        << ", position: " << position[i] << " ->" << circleOfNumbers(numbers[i], position[i])
        << std::endl;
    }
	return 0;
}
