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
                digit = false;
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
        if (!(numberString[idex] >= '0' && numberString[idex] <= '9'))
        {
            return false;
        }
        if (numberString[idex] == '0')
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

    if (checkZeros(s1, countZeros1) && checkZeros(s2, countZeros2))
    {
        if (countZeros1 > countZeros2)
            return true;
        if (countZeros1 < countZeros2)
            return false;
    }

    int limt = tokens1.size() < tokens2.size() ? tokens1.size() : tokens2.size();

    for (int idex = 0; idex < limt; idex++)
    {
        string _s1 = tokens1[idex];
        string _s2 = tokens2[idex];
        if (_s1[0] >= '0' && _s1[0] <= '9' && _s2[0] >= '0' && _s2[0] <= '9')
        {
            if (stoi(_s1) < stoi(_s2))
                return true;
            if (stoi(_s1) > stoi(_s2))
                return false;
            if (checkZeros(_s1, countZeros1) && checkZeros(_s2, countZeros2))
            {
                if (countZeros1 > countZeros2)
                {
                    return true;
                }
            }
        }
        else
        {
            if (_s1 < _s2)
                return true;
            if (_s1 > _s2)
                return false;
        }
    }

    if (tokens1.size() < tokens2.size())
        return true;
    return false;
}

int main()
{
    //cout << stoi("0123") << endl << endl;
    cout << alphanumericLess("0000", "000") << endl
         << endl;
    cout << alphanumericLess("000124", "000000124") << endl
         << endl;
    cout << alphanumericLess("ab", "a1") << endl
         << endl;
    cout << alphanumericLess("x11y012", "x011y13") << endl
         << endl;
    cout << alphanumericLess("x11y012aaaa000000002312000", "x011y13aaaa00000003212") << endl
         << endl;
    cout << alphanumericLess("x11y013aaaaxccqds", "x011y13aaaa0") << endl
         << endl;
    return 0;
}