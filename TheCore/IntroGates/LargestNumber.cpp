/*
Given an integer n, return the largest number that contains exactly n digits.

Example

For n = 2, the output should be
largestNumber(n) = 99.
*/
#include <iostream>

int largestNumber(int n) {
    int output = 9;
	int i = 2;
	if (n == 1)
	{
		return output;
	}
	while (i <= n)
	{
		output = output * 10 + 9;
		i++;
	}

	return output;
}

int main()
{
    std::cout << largestNumber(3);

    return 0;
}
