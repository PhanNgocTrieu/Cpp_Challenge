//Given a rectangular matrix of characters, add a border of asterisks(*) to it.
//
//Example
//
//For
//
//picture = ["abc", //size of pic = 2;
//           "ded"] //size of pic[i] = 3;
//the output should be
//
//addBorder(picture) = ["*****", //size of picture = 4; if row == 0 => push all '*'
//                      "*abc*", //size of picture[i] = 5; if cols == 0 or cols == picture[i].leng() - 1 => push('*');
//                      "*ded*",
//                      "*****"] // if rows == picture.size() - 1 => string pushes all '*'

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> addBorder(std::vector<std::string> picture) {
	
	std::vector<std::string> output;
	int size_push = picture.size();
	int size_pop = picture.size() + 2;
	std::vector<char> temp_char;
	int pos = 0;
	//push characters in vetor;
	for (int i = 0; i < size_push; i++)
	{
		int len = picture[i].length();
		for (int j = 0; j < len; j++)
		{
			temp_char.push_back(picture[i][j]);
		}
	}

	//printing to check
	for (int i = 0; i < temp_char.size(); i++)
	{
		std::cout << temp_char[i] << " ";
	}
	std::cout << std::endl;

	//assign to output:
	for (int i = 0; i < size_pop ; i++)
	{
		int len = picture[0].length() + 2; // take a length of all
		std::string temp_str;
		for (int j = 0; j < len; j++)
		{
			if (i == 0 || i == size_pop - 1)
			{
				temp_str.push_back('*');
			}
			else
			{
				// if j == 0 or len - 1 => strig is '*'
				if (j == 0 || j == len - 1)
				{
					temp_str.push_back('*');
				}
				else
				{
					temp_str.push_back(temp_char[pos]);
					pos++;
				}
			}
		}
		output.push_back(temp_str);
	}
	// print output to check:
	for (int i = 0; i < output.size(); i++)
	{
		std::cout << output[i] << std::endl;
	}
	std::cout << std::endl;

	return output;
}


int main()
{
	std::vector<std::string> picture = { "abc","***","ded" };
	/*std::string str;
	for (int i = 0; i < 10; i++)
	{
		str.push_back('*');
	}
	std::cout << str;*/

	addBorder(picture);
	return 0;
}
