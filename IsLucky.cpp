//Ticket numbers usually consist of an even number of digits.A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.
//
//Given a ticket number n, determine if it's lucky or not.
//
//Example
//
//For n = 1230, the output should be
//isLucky(n) = true;
//For n = 239017, the output should be
//isLucky(n) = false;
//Bonus: For n = 23023, the output should be
//isLucky(n) = True;

#include <iostream>
#include <vector>

bool isLucky(int n) {
	std::vector<int> int_num;
	int sum_left = 0;
	int sum_right = 0;
	//pushing all of element of n;
	while (n > 0)
	{
		int_num.push_back(n % 10);
		n = n / 10;
	}
	int size = int_num.size();
	//std::cout << size;
	if (size % 2 == 0) // checking if size is even;
	{
		int left = 0;
		int right = size - 1;
		while (left < right)
		{
			sum_left += int_num[left];
			sum_right += int_num[right];
			left++;
			right--;
		}
	}
	else
	{
		int_num.push_back(0);
		int left = 0;
		int right = size;
		while (left < right)
		{
			sum_left += int_num[left];
			sum_right += int_num[right];
			left++;
			right--;
		}
	}

	if (sum_left == sum_right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	if (isLucky(999999) == true)
	{
		std::cout << "True!" << std::endl;
	}
	else
	{
		std::cout << "False!" << std::endl;
	}
	return 0;
}
