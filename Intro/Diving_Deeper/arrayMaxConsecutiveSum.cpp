//Given array of integers, find the maximal possible sum of some of its k consecutive elements.
//
//Example
//
//For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
//arrayMaxConsecutiveSum(inputArray, k) = 8.
//All possible sums of 2 consecutive elements are :
//
//2 + 3 = 5;
//3 + 5 = 8;
//5 + 1 = 6;
//1 + 6 = 7.
//Thus, the answer is 8.

#include <iostream>
#include <vector>

int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k) {
	int max = 0;

	for (int i = 0; i <= inputArray.size() - k; i++)
	{
		int index = i;
		int j = 0;
		int sum = 0;
		while (j < k)
		{
			sum += inputArray[index];
			j++;
			index++;
		}
		if (max < sum)
		{
			max = sum;
		}
	}
	return max;
}


int main()
{
	std::vector<int> inputArray = { 1,3,2,5,7,9,2 };
	std::cout << arrayMaxConsecutiveSum(inputArray,2);
}
