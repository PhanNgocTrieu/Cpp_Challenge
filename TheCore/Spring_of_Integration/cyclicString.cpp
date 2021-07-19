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
    int len = s.length();

    for (int idex = 1; idex <= len; idex++)
    {
        bool check = false;
        for (int jdex = 0; jdex + idex <= len; jdex++)
        {
            string subCyclic(s.begin() + jdex, s.begin() + jdex + idex);
            cout << "subCyclic: " << subCyclic << endl;
            string p;
            for (int zDex = 1; zDex <= len * 3; zDex++)
            {
                p += subCyclic;
            }
            if (p.find(s) != string::npos)
                check = true;
        }
        if (check)
            return idex;
    }

    return len;
    
}

int main()
{
    cout << cyclicString("acbac") << endl;
    
    //cout << cyclicString("abcba") << endl;
    return 0;
}