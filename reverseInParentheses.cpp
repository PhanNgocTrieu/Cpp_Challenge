//Write a function that reverses characters in(possibly nested) parentheses in the input string.
//Input strings will always be well - formed with matching()s.
//
//Example
//For inputString = "(bar)", the output should be
//reverseInParentheses(inputString) = "rab";
//For inputString = "foo(bar)baz", the output should be
//reverseInParentheses(inputString) = "foorabbaz";
//For inputString = "foo(bar)baz(blim)", the output should be
//reverseInParentheses(inputString) = "foorabbazmilb";
//For inputString = "foo(bar(baz))blim", the output should be
//reverseInParentheses(inputString) = "foobazrabblim".
//Because "foo(bar(baz))blim" becomes "foo(barzab)blim" and then "foobazrabblim".
//
//Input / Output:
//[execution time limit] 0.5 seconds(cpp)
//[input] string inputString
//A string consisting of lowercase English letters and the characters(and).
//It is guaranteed that all parentheses in inputString form a regular bracket sequence.
//Guaranteed constraints : //0 ≤ inputString.length ≤ 50.
//[output] string
//Return inputString, with all the characters that were in parentheses reversed.

#include <iostream>
#include <string>
#include <vector>
#include <string.h>


void Removing(std::string &inputString, int position)
{
	int size = inputString.length();
	for (int i = position + 1; i < size; i++)
	{
		inputString[i - 1] = inputString[i];
	}
	inputString.pop_back();
}
void reverseInParentheses(std::string& inputString) {

	int size = inputString.length();
	int last_open = 0;
	int first_close = size;
	do
	{
		for (int i = 0; i < size; i++)
		{
			if (inputString[i] == '(')
			{
				if (i > last_open)
				{
					last_open = i;
				}
			}
		}
		//deleta last '('
		Removing(inputString, last_open);

		for (int i = size - 1; i >=0; i--)
		{
			if (inputString[i] == '(')
			{
				if (i < first_close)
				{
					first_close = i;
				}
			}
		}
		//delete fist ')'
		Removing(inputString, first_close);
		for (int i = last_open; last_open < first_close; i++)
		{
    
			char temp = inputString[i];
			inputString[i] = inputString[first_close];
			inputString[first_close] = temp;
			first_close--;
		}

	} while (inputString.find('(') == std::string::npos);
}

int main()
{
	std::string str = "I'm (nhoJ), (81) years old!";
	std::cout << "Before reverse: " << str << std::endl;
	reverseInParentheses(str);
	std::cout << "After reverse: " << str << std::endl;
	return 0;
}
