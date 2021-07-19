//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//
//
//Example 1:
//
//Input: s = "()"
//Output : true
//Example 2 :
//
//	Input : s = "()[]{}"
//	Output : true
//	Example 3 :
//
//	Input : s = "(]"
//	Output : false
//	Example 4 :
//
//	Input : s = "([)]"
//	Output : false
//	Example 5 :
//
//	Input : s = "{[]}"
//	Output : true

#include <iostream>
#include <stack>
#include <map>

using namespace std;



bool isValid(string s) {
	if (s.length() == 1)
		return false;
	if (s[0] == '}' || s[0] == ']' || s[0] == ')')
		return false;

	stack<char> check;
	map<char, char> brackets{
		{')','('},
		{'}','{'},
		{']','['}
	};
	
	for (char c : s)
	{
		if (c == '(' || c == '{' || c == '[')
			check.push(c);
		else
		{
			if (check.empty())
				return false;
			if (check.top() == brackets[c])
				check.pop();
			else
				return false;
		}
	}
	return check.size() == 0 ? true : false;
}

int main()
{

	if (isValid("(){}}{")) // output : Invalid
		cout << "\nValid!" << endl;
	else
	{
		cout << "\nInvalid!" << endl;
	}
	return 0;
}
