/*

You're given a substring s of some cyclic string. 
What's the length of the smallest possible string that can be concatenated to itself many times to obtain this cyclic string?

Example

For s = "cabca", the output should be
cyclicString(s) = 3.

"cabca" is a substring of a cycle string "abcabcabcabc..." that can be obtained by concatenating "abc" to itself. 
Thus, the answer is 3.

*/

#include <iostream>

using namespace std;

int cyclicString(string s) {
    
    cout << "substr: " << s.substr(0,3) << endl;
    int len = s.length();
    bool notOne = false;
    for (int idex = 1; idex < len; idex++)
    {
        if (s[idex] != s[0])
        {
            notOne = true;
            break;
        }
    }

    if (notOne == false)
        return 1;
    
    string took = "";
    int idex = 0;
    for (; idex < len; idex++)
    {
        if (took == "")
            took.push_back(s[idex]);
        else
        {
            if (s[idex] == took[0])
            {
                string sub;
                if (len - idex <= took.length())
                {
                    sub = s.substr(idex, len - idex);;
                    string sub_Took = took.substr(0, len - idex);
                    cout << "Sub: " << sub << endl;
                    if (sub != sub_Took)
                        took += sub;
                    break;
                }
                else
                {
                    sub = s.substr(idex, took.length());
                    if (sub != took)
                        took += sub;
                    idex += took.length();
                }
            }
            else
                took.push_back(s[idex]);
        }
    
    }

    cout << "Took: " << took << endl;
    return took.length();
}

int main()
{
    cout << cyclicString("acbac") << endl;
    
    cout << cyclicString("abcba") << endl;
    return 0;
}