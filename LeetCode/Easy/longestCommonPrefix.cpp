//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//
//
//Example 1:
//
//Input: strs = ["flower", "flow", "flight"]
//Output : "fl"
//Example 2 :
//
//	Input : strs = ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.

/*
* Algorithm:
* 
* from above example we can see:
* taking the first element is standard:
* strs[0] ------ f ------- l ------- o 
* checking: 
* strs[1] ------ ^ ------- ^ ------- ^
* strs[2] ------ ^ ------- ^ ------- x -> resturn res
* --------------------------------------
* res =          f        fl        return
* 
* 
*/

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 1)
		return strs[0];

	string res = "";
	int size = strs.size();
	int len = strs[0].length();
	for (int i = 0; i < len; i++)
	{
		char c = strs[0][i];
		for (int j = 1; j < size; j++)
		{
			if (strs[j][i] != c)
			{
				return res;
			}
		}
		res += c;
	}


	return res;
}
