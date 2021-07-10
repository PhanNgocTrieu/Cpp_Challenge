//Let's define digit degree of some positive integer as the number of times 
//we need to replace this number with the sum of its digits until we get to a one digit number.
//
//Given an integer, find its digit degree.
//
//Example
//
//For n = 5, the output should be
//digitDegree(n) = 0;
//For n = 100, the output should be
//digitDegree(n) = 1.
//1 + 0 + 0 = 1.
//For n = 91, the output should be
//digitDegree(n) = 2.
//9 + 1 = 10 -> 1 + 0 = 1.

#include <iostream>

int digitDegree(int n) {
	int count = 0;
	int sum = n;
	if (n < 10)
	{
		return 0;
	}
	while (sum >= 10)
	{
		int temp_sum = 0;
		int div = sum;
		while (div > 0)
		{
			int temp = div % 10;
			temp_sum = temp_sum + temp;
			div = div / 10;
		}

		count++;
		sum = temp_sum;

	}

	return count;
}

int main()
{
	int n = 505;
	std::cout << digitDegree(n);
	return 0;
}
