// Given two strings a and b, both consisting only of lowercase English letters,
// your task is to calculate how many strings equal to a can be constructed using only letters from the string b?
// Each letter can be used only once and in one string only.

// Example

// For a = "abc" and b = "abccba", the output should be stringsConstruction(a, b) = 2.

// We can construct 2 strings a = "abc" using only letters from the string b.

// For a = "ab" and b = "abcbcb", the output should be stringsConstruction(a, b) = 1.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int stringsConstruction(std::string a, std::string b) {
    int min = 9999;
	std::vector<char> vec_char;
	std::map<char, int> pair_ch_num_a;
    std::map<char, int> pair_ch_num_b;

	for (char c : a)
	{
		if (std::find(vec_char.begin(),vec_char.end(),c) == vec_char.end())
			vec_char.push_back(c);
	}
	
	for (int i = 0; i < vec_char.size(); i++)
	{
		pair_ch_num_a.insert(std::make_pair(vec_char[i], std::count(a.begin(), a.end(), vec_char[i])));
		pair_ch_num_b.insert(std::make_pair(vec_char[i], std::count(b.begin(), b.end(), vec_char[i])));
	}
	
	std::map<char, int>::iterator it;
	for (int i = 0; i < vec_char.size(); i++)
	{
		std::cout << "#" << vec_char[i] << ":";
		
		const int count_c = pair_ch_num_b[vec_char[i]] / pair_ch_num_a[vec_char[i]];
		std::cout << pair_ch_num_a[vec_char[i]] << "--" << pair_ch_num_b[vec_char[i]] <<" count = " << count_c << " \n";
		if (count_c < min)
			min = count_c;
	}
	std::cout << "\n";
    return min;
}


int main()
{
    std::cout << stringsConstruction("hnccv","hncvohcjhdfnhonxddcocjncchnvohchnjohcvnhjdhihsn");
	
    return 0;
}
