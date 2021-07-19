/*Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string ? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().



Example 1:

Input: haystack = "hello", needle = "ll"
Output : 2
Example 2 :

	Input : haystack = "aaaaa", needle = "bba"
	Output : -1
	Example 3 :

	Input : haystack = "", needle = ""
	Output :0
  
  */


#include <iostream>
using namespace std;
int strStr(string haystack, string needle) {
    if (haystack.length() == 0 && needle.length() == 0)
        return 0;

    int needle_length = needle.length();

    for (int index = 0; index < haystack.length(); index++)
    {
        string temp = haystack.substr(index, needle_length);
        if (temp == needle)
            return index;
    }

    return -1;
}
