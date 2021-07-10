/*
An alphanumeric ordering of strings is defined as follows: each string is considered as a sequence of tokens,
where each token is a letter or a number (as opposed to an isolated digit, 
as is the case in lexicographic ordering). 
For example, the tokens of the string "ab01c004" are [a, b, 01, c, 004]. 
In order to compare two strings, 
we'll first break them down into tokens and then compare the corresponding pairs of tokens with each other 
(i.e. compare the first token of the first string with the first token of the second string, etc).

Here is how tokens are compared:

If a letter is compared with another letter, the usual alphabetical order applies.
A number is always considered less than a letter.
When two numbers are compared, their values are compared. Leading zeros, if any, are ignored.
If at some point one string has no more tokens left while the other one still does, 
the one with fewer tokens is considered smaller.

If the two strings s1 and s2 appear to be equal, consider the smallest index i such that 
tokens(s1)[i] and tokens(s2)[i] (where tokens(s)[i] is the ith token of string s) differ only 
by the number of leading zeros. If no such i exists, the strings are indeed equal. 
Otherwise, the string whose ith token has more leading zeros is considered smaller.

Here are some examples of comparing strings using alphanumeric ordering.

"a" < "a1" < "ab"
"ab42" < "ab000144" < "ab00144" < "ab144" < "ab000144x"
"x11y012" < "x011y13"
Your task is to return true if s1 is strictly less than s2, and false otherwise.

Example

For s1 = "a" and s2 = "a1", the output should be alphanumericLess(s1, s2) = true;

These strings have equal first tokens, but since s1 has fewer tokens than s2, it's considered smaller.

For s1 = "ab" and s2 = "a1", the output should be alphanumericLess(s1, s2) = false;

These strings also have equal first tokens, but since numbers are considered less than letters, s1 is larger.

For s1 = "b" and s2 = "a1", the output should be alphanumericLess(s1, s2) = false.

Since b is greater than a, s1 is larger.
*/

#include <iostream>
#include <vector>

using namespace std;

void splitString(vector<string> &vs, string s)
{
    if (s == "")
    {
        return;
    }
    int len = s.length();
    string str = "";
    bool digit = false;
    for (int idex = 0; idex < len; idex++)
    {
        if (s[idex] >= '0' && s[idex] <= '9')
        {
            str += s[idex];
            digit = true;
        }
        else
        {
            if (digit)
            {
                vs.push_back(str);
                str = "";
            }
            str += s[idex];
            vs.push_back(str);
            str = "";
        }
    }

    if (digit == true)
        vs.push_back(str);
}

bool checkZeros(string numberString, int &_countZeros)
{
    int len = numberString.size();
    for (auto idex = 0; idex < len; idex++)
    {
        if (numberString[idex] != '0')
            return false;
        _countZeros++;
    }
    return true;
}
bool alphanumericLess(string s1, string s2)
{
    vector<string> tokens1;
    vector<string> tokens2;
    int countZeros1 = 0;
    int countZeros2 = 0;
    splitString(tokens1, s1);
    splitString(tokens2, s2);

    for (auto it = tokens1.begin(); it != tokens1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = tokens2.begin(); it != tokens2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int limit = tokens1.size() < tokens2.size() ? tokens1.size() : tokens2.size();

    for (int idex = 0; idex < limit; idex++)
    {
        // handling letter
        string str1 = tokens1[idex];
        string str2 = tokens2[idex];
        int iternal_limit = str2.length() < str1.length() ? str2.length() : str1.length();
        if ((str1[0] >= '0' && str1[0] <= '9') && (str2[0] >= '0' && str2[0] <= '9'))
        {
            if (stoi(str1) < stoi(str2))
            {
                return true;
            }
            if (stoi(str1) > stoi(str2))
            {
                return false;
            }
            if (stoi(str1) == stoi(str2))
            {
                // all is 0s
                if (checkZeros(str1, countZeros1) && checkZeros(str2, countZeros2))
                {
                    return countZeros1 > countZeros2 ? true : false;
                }
                else
                {
                    // 000124 vs 00124
                    if (countZeros1 > countZeros2)
                    {
                        return true;
                    }
                    if (countZeros1 < countZeros2)
                        return false;
                }
            }
        }
        else
        {
            for (int jdex = 0; jdex < iternal_limit; jdex++)
            {
                if (str1[jdex] < str2[jdex])
                {
                    return true;
                }
                if (str1[jdex] > str2[jdex])
                {
                    return false;
                }
            }
        }
    }

    if (tokens1.size() < tokens2.size())
    {
        return true;
    }
    return false;
}

int main()
{
    //cout << stoi("0123") << endl;
    // cout << alphanumericLess("0000", "000") << endl;
    // cout << alphanumericLess("000124", "00124") << endl;
    // cout << alphanumericLess("ab", "a1") << endl;
    // cout << alphanumericLess("x11y012", "x011y13") << endl;
    // cout << alphanumericLess("x11y012aaaa000000002312000", "x011y13aaaa00000003212") << endl;
    cout << alphanumericLess("x11y013aaaaxccqds", "x011y13aaaa0") << endl;
    return 0;
}