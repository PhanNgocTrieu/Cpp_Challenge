/*
Consider a string containing only letters and whitespaces. 
It is allowed to replace some (possibly, none) whitespaces with newline symbols 
to obtain a multiline text. 

Call a multiline text beautiful if and only if each of its lines 
(i.e. substrings delimited by a newline character) contains an equal number of characters 
(only letters and whitespaces should be taken into account when counting the total 
while newline characters shouldn't). Call the length of the line the text width.

Given a string and some integers l and r (l ≤ r), 
check if it's possible to obtain a beautiful text from the string with a text width that's 
within the range [l, r].

Example:

For inputString = "Look at this example of a correct text", l = 5, and r = 15, the output should be
beautifulText(inputString, l, r) = true.

We can replace 13th and 26th characters with '\n', and obtain the following multiline text of width 12:

Look at this example of a correct text
For inputString = "abc def ghi", l = 4, and r = 10, the output should be
beautifulText(inputString, l, r) = false.

There are two ways to obtain a text with lines of equal length from this input, 
one has width = 3 and another has width = 11 (this is a one-liner). 
Both of these values are not within our bounds.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool  beautifulText(string inputString, int l, int r)
{
    int len = inputString.length();
    cout << "len: " << len << endl;
    for (int idex = l; idex <= r; idex++)
    {
        if (len % (idex + 1) == idex)
        {
            cout << "idex: " << idex << endl;
            bool beautiful = true;
            int small_len = floor((len + 1) / (idex+1) - 1);
            cout << "small_len: " << small_len << endl;
            for (int jdex = 0; jdex < small_len ; jdex++)
            {
                string s = inputString.substr(jdex,idex);
                if (inputString[ (jdex+1) * (idex + 1) -1] != ' ')
                {
                    beautiful = false;
                    break;
                }
            }
            if (beautiful)
                return true;
        }
        
    }
    cout << "False! " << endl;
    return false;
}

int main()
{
    // string test = "abcd abcd abcd";
    // string s = test.substr(0,5);
    // string s2 = test.substr(5,5);
    // string s3 = test.substr(10,5);

    // cout << "s: " << s << endl;
    // cout << "s2: " << s2 << endl;
    // cout << "s3: " << s3 << endl;

    if (beautifulText("Look at this example of a correct text", 5, 15))
    {
        cout << "True!" << endl;
    }

    return 0;
}