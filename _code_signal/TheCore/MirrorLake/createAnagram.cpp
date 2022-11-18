/*
You are given two strings sand t of the same length, consisting of uppercase English letters.
Your task is to find the minimum number of "replacement operations" needed to get some anagram of the string t from the string s.
A replacement operation is performed by picking exactly one character from the string s and replacing it by some other character.

Example

For s = "AABAA" and t = "BBAAA", the output should be
createAnagram(s, t) = 1;
For s = "OVGHK" and t = "RPGUC", the output should be
createAnagram(s, t) = 4.



Algorithm:
s1: A - 4 | B - 1
s2: A - 3 | B - 2

we can see that if we replace B of s2 by A of s2 -> we can have a string which was built from s1 when we arrange s1.

it means we can find the max of difference between 2 string (s1 -> s2) -- they all are the same length. so don't worry about the length of them.
-------------------
difference_s = [s1(A) > s2(A) ? count_s1(A) - count_s2(A) : 0) + s1(B) > s2(B) ? count_s1(B) - count_s2(B) : 0)]

*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

int createAnagram(std::string s, std::string t) {
	if (s == t)
		return 0;
	std::vector<char> saved_letter;
	int step = 0;
	int difference_s = 0;
	for (char c : s)
	{
		if (std::find(saved_letter.begin(), saved_letter.end(), c) == saved_letter.end())
		{
			saved_letter.push_back(c);
			//std::cout << "Going here!\n";
			int count_s = std::count(s.begin(), s.end(), c);
			int count_t = std::count(t.begin(), t.end(), c);

			if (count_s > count_t)
			{
				std::cout << "step:" << step++ << " letter: " << c << " -- "; 
				std::cout << "count_s: " << count_s << " - count_t: " << count_t << "\n";
				difference_s += count_s - count_t;
				std::cout << "difference: " << difference_s << std::endl;
			}
		}
	}
	return difference_s;
}


int main()
{
	std::cout << createAnagram("AABCDS", "BASEAE"); //output should be: 2
  std::cout << createAnagram("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"); //output should be: 0
  std::cout << createAnagram("HDFFVR", "FEDDEE"); //output should be: 4
  std::cout << createAnagram("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYZ"); //output should be: 31
  
	return 0;
}
