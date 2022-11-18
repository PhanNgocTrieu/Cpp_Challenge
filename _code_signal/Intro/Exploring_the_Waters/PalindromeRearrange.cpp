//Given a string, find out if its characters can be rearranged to form a palindrome.
//Example
//For inputString = "aabb", the output should be
//palindromeRearranging(inputString) = true.
//We can rearrange "aabb" to make "abba", which is a palindrome.
/*
Algorithm:
A set of characters can form a palindrome if at most one character occurs odd number of times and all characters occur even number of times.

A simple solution is to run two loops, the outer loop picks all characters one by one, the inner loop counts number of occurrences of the picked character. 
We keep track of odd counts. Time complexity of this solution is O(n2).

We can do it in O(n) time using a count array. Following are detailed steps.
1) Create a count array of alphabet size which is typically 256. Initialize all values of count array as 0.
2) Traverse the given string and increment count of every character.
3) Traverse the count array and if the count array has more than one odd values, return false. Otherwise return true.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool palindromeRearranging(std::string inputString) {
	int found_odd = 0;
	//finding count off all characters in string
	for (int i = 0; i < 25; i++)
	{
		char c = 'a' + i;
		auto count = std::count(inputString.begin(), inputString.end(), c);

		if (count % 2 != 0)
		{
			found_odd++;
		}
		if (found_odd > 1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::string inputString = "abbcabb";
	string temp = inputString;
	int c = 0;

	if (palindromeRearranging(inputString) == true)
	{
		std::cout << "TRUE!" << std::endl;
	}
	else
	{
		std::cout << "FALSE!" << std::endl;
	}
	//everse(inputString.begin(), inputString.end());


	return 0;
}
