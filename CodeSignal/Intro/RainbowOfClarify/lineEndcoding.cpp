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
    std::string s = "abbcabb"; // -> output: a2bca2b
    lineEncoding(s);
    return 0;
}