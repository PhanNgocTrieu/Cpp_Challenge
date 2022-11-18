//Given an array of equal - length strings, 
//you'd like to know if it's possible to rearrange the order of the elements in such a way that
//each consecutive pair of strings differ by exactly one character. 
//Return true if it's possible, and false if not.
//
//Note: You're only rearranging the order of the strings, 
//not the order of the letters within the strings!
//
//Example
//
//For inputArray = ["aba", "bbb", "bab"], the output should be
//stringsRearrangement(inputArray) = false.
//
//There are 6 possible arrangements for these strings :
//
//["aba", "bbb", "bab"]
//["aba", "bab", "bbb"]
//["bbb", "aba", "bab"]
//["bbb", "bab", "aba"]
//["bab", "bbb", "aba"]
//["bab", "aba", "bbb"]
//None of these satisfy the condition of consecutive strings differing by 1 character,
//so the answer is false.
//
//For inputArray = ["ab", "bb", "aa"], the output should be
//stringsRearrangement(inputArray) = true.
//
//It's possible to arrange these strings
//in a way that each consecutive pair of strings differ by 1 character 
//(eg: "aa", "ab", "bb" or "bb", "ab", "aa"), so return true.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



int dist(const std::string& s1, const std::string& s2)
{
	int count = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			count++;
		}
	}
	return count;
}


bool check(const std::vector<std::string>& a)
{
	for (int i = 0; i < a.size() - 1; ++i)
	{
		int j = i + 1;
		if (dist(a[i],a[j]) != 1)
		{
			return false;
		}
	}
	return true;
}

bool stringsRearrangement(std::vector<std::string> inputArray) {
	
	std::sort(inputArray.begin(), inputArray.end());
	if (check(inputArray))
	{
		return true;
	}

	while (std::next_permutation(inputArray.begin(),inputArray.end())) // liên tục thay đổi trật tự các phần tử theo thứ tự của các chữ cái cho đến khi phần tử tiếp theo không còn nữa thì dừng lại   
	{
		if (check(inputArray))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	std::vector<std::string> inputArray = { "p", "p"};
	if (stringsRearrangement(inputArray) == true)
		std::cout << "True!\n";
	else
		std::cout << "False!\n";
	return 0;
}
