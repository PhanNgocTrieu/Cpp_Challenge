//Given two strings, find the number of common characters between them.
//
//Example
//
//For s1 = "aabcc" and s2 = "adcaa", the output should be
//commonCharacterCount(s1, s2) = 3.
//
//Strings have 3 common characters - 2 "a"s and 1 "c".

#include <iostream>
#include <string>
#include <vector>

int commonCharacterCount(std::string s1, std::string s2) {
	int total = 0;
	std::vector<char> char_vect;
	int size_s1 = s1.size();
	int size_s2 = s2.size();
	// passing through all elements in array
	for (int i = 0; i < size_s1; i++)
	{
		//checking exist in previous elements or not!
		if (char_vect.empty())
		{
			char_vect.push_back(s1[i]);
		}
		else
		{
			bool IsExist = false; // suppose that s1[i] is available for adding in char_vect;
			for (int j = 0; j < char_vect.size(); j++)
			{
				if (s1[i] == char_vect[j])
				{
					IsExist = true;
				}
			}
			if (IsExist == false)
			{
				//push_back element which is not in char_vect;
				char_vect.push_back(s1[i]);
			}
		}
	}
	for (int i = 0; i < size_s2; i++)
	{
		//checking exist in previous elements or not!
		// suppose that s1[i] is available for adding in char_vect;
		if (char_vect.empty())
		{
			char_vect.push_back(s2[i]);
		}
		else
		{
			bool IsExist = false; // suppose that s2[i] is available for adding in char_vect;
			for (int j = 0; j < char_vect.size(); j++)
			{
				if (s2[i] == char_vect[j])
				{
					IsExist = true;
				}
			}
			if (IsExist == false)
			{
				//push_back element which is not in char_vect;
				char_vect.push_back(s2[i]);
			}
		}
	}
	for (int i = 0; i < char_vect.size(); i++)
	{
		std::cout << char_vect[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < char_vect.size(); i++)
	{
		int count_s1 = 0;
		int count_s2 = 0;
		for (int j = 0; j < s1.size(); j++)
		{
			if (s1[j] == char_vect[i])
			{
				count_s1++;
			}
		}
		for (int j = 0; j < s2.size(); j++)
		{
			if (s2[j] == char_vect[i])
			{
				count_s2++;
			}
		}
		if (count_s1 >= count_s2)
		{
			total += count_s2;
		}
		else
		{
			total += count_s1;
		}
	}

	return total;
}


int main()
{
	std::string s1 = "aabcc";
	std::string s2 = "adcaa";
	std::vector<char> vect;

	/*std::cout << s1.size() << std::endl;
	std::cout << s2.size() << std::endl;
	for (int i = 0; i < s1.size(); i++)
	{
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;*/

	std::cout << commonCharacterCount(s1, s2) << std::endl;
	return 0;
}
