//Given a sorted array of integers a, your task is to determine 
//which element of a is closest to all other values of a.In other words,
//find the element x in a, which minimizes the following sum :
//
//abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.length - 1] - x)
//(where abs denotes the absolute value)
//
//If there are several possible answers, output the smallest one.
//
//Example
//
//For a = [2, 4, 7], the output should be absoluteValuesSumMinimization(a) = 4.
//
//for x = 2, the value will be abs(2 - 2) + abs(4 - 2) + abs(7 - 2) = 7.
//for x = 4, the value will be abs(2 - 4) + abs(4 - 4) + abs(7 - 4) = 5.
//for x = 7, the value will be abs(2 - 7) + abs(4 - 7) + abs(7 - 7) = 8.
//The lowest possible value is when x = 4, so the answer is 4.
//
//For a = [2, 3], the output should be absoluteValuesSumMinimization(a) = 2.
//
//for x = 2, the value will be abs(2 - 2) + abs(3 - 2) = 1.
//for x = 3, the value will be abs(2 - 3) + abs(3 - 3) = 1.
//Because there is a tie, the smallest x between x = 2 and x = 3 is the answer.


#include <iostream>
#include <vector>
#include <math.h>

int absoluteValuesSumMinimization(std::vector<int> a) {
	int len = a.size();
	int res = 0;
	int min = 99999999; // chose max of this type! if we have elements more than min -> return will be wrong
	//sum = abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.size() - 1] - x)
	for (int i = 0; i < len; i++)
	{
		float sum = 0;
		int x = a[i];
		for (int j = 0; j < len; j++)
		{
			sum = sum + abs(a[j] - x);
		}
		std::cout << "case a[" << i << "] = " << a[i] << " -> " << sum << std::endl;
		if (sum < min)
		{
			min = sum;
			res = a[i];
		}
	}
	
	return res;
}


int main()
{
	std::vector<int> a = { 2,4,7 };
	std::cout << "Absolute Values Minimization -> " << absoluteValuesSumMinimization(a) << std::endl;
	return 0;
}


/*  solution:
	case a[0] = 2 -> 7
	case a[1] = 4 -> 5
	case a[2] = 7 -> 8
	Absolute Values Minimization -> 4
*/
