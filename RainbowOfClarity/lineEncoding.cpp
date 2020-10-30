//Given a string, return its encoding defined as follows :
//
//First, the string is divided into the least possible number of disjoint substrings
//consisting of identical characters
//for example, "aabbbc" is divided into["aa", "bbb", "c"]
//Next, each substring with length greater than one is replaced with a concatenation of its lengthand
//the repeating character
//for example, substring "bbb" is replaced by "3b"
//Finally, all the new strings are concatenated together in the same orderand a new string is returned.
//Example
//
//For s = "aabbbc", the output should be
//lineEncoding(s) = "2a3bc".

#include <iostream>
#include <string>
#include <algorithm>

std::string lineEncoding(std::string s) {
    std::string res = "";
    int length = s.length();
    int i = 0;

    while (i < length)
    {
        char c = s[i];
        int j = i;
        int next_j = j + 1;
        int count_same = 1;
        while ((s[j] == s[next_j]) && (j < length - 1))
        {
            count_same++;
            j++;
            next_j++;
        }
        if (count_same == 1)
        {
            // s = abcdge
            res += s[i];
        }
        else
        {
            // s = 2a3b5c....
            res += std::to_string(count_same);
            res += s[i];
        }
        std::cout << res << "\n";
        i += count_same;
    }
    return res;
}

int main()
{
    std::string s = "abbcabb";
    lineEncoding(s);
    return 0;
}
