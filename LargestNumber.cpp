//Given an integer n, return the largest number that contains exactly n digits.
//
//Example
//
//For n = 2, the output should be
//largestNumber(n) = 99.
//
//Input / Output
//
//[execution time limit] 0.5 seconds(cpp)
//
//[input] integer n
//
//Guaranteed constraints :
//1 ≤ n ≤ 9.
//
//[output] integer
//
//The largest integer of length n.

#include <iostream>
#include <vector>
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
	std::cout << largestNumber(10);
	return 0;
}
