/*
Given two version strings composed of several non-negative decimal fields separated by periods ("."),
both strings contain equal number of numeric fields. 
eturn true if the first version is higher than the second version and false otherwise.

The syntax follows the regular semver ordering rules:

1.0.5 < 1.1.0 < 1.1.5 < 1.1.10 < 1.2.0 < 1.2.2
< 1.2.10 < 1.10.2 < 2.0.0 < 10.0.0
There are no leading zeros in any of the numeric fields, 
i.e. you do not have to handle inputs like 100.020.003 (it would instead be given as 100.20.3).

Example

For ver1 = "1.2.2" and ver2 = "1.2.0", the output should be
higherVersion(ver1, ver2) = true;
For ver1 = "1.0.5" and ver2 = "1.1.0", the output should be
higherVersion(ver1, ver2) = false.
*/


#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int calFields(string ver)
{
    int sum = 0;
    for (char c : ver)
    {
        sum += (int)c;
    }
    return sum;
}

bool higherVersion(string ver1, string ver2) {
    if (ver1 == ver2)
    {
        return false;
    }
    stringstream ss(ver1);
    vector<string> version1;
    string words;
    while(getline(ss,words,'.'))
    {
        version1.push_back(words);
    }
    stringstream ss2(ver2);
    vector<string> version2;
    while(getline(ss2,words,'.'))
    {
        version2.push_back(words);
    }
    
    for (int idex = 0; idex < version1.size(); idex++)
    {
        int ver1Field = calFields(version1[idex]);
        int ver2Field = calFields(version2[idex]);
        if (ver1Field > ver2Field)
        {
            return true;
        }
        if (ver2Field > ver1Field)
        {
            return false;
        }
    }
    return false;
}


int main()
{

    return 0;
}