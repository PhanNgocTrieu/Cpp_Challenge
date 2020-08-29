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
#include <stack>
#include <algorithm>

void reverseInParentheses(std::string &inputString) {
    std::stack<char> st;
    int len = inputString.length();
    for (int i = 0; i < len; i++) {

        // Push the index of the current 
        // opening bracket 
        if (inputString[i] == '(') {
            st.push(i);
        }

        // Reverse the substring starting 
        // after the last encountered opening 
        // bracket till the current character 
        else if (inputString[i] == ')') {
            reverse(inputString.begin() + st.top() + 1,
                inputString.begin() + i);
            st.pop();
        }
    }

    // To store the modified string 
    std::string res = "";
    for (int i = 0; i < len; i++) {
        if (inputString[i] != ')' && inputString[i] != '(')
            res += (inputString[i]);
    }
    inputString = res;
}

int main()
{
	std::string str = "I'm (nhoJ), (81) years old!";
	std::cout << "Before reverse: " << str << std::endl;
	reverseInParentheses(str);
	std::cout << "After reverse: " << str << std::endl;
	return 0;
}
