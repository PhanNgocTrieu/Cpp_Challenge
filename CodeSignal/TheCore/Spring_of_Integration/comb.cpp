/*
Miss X has only two combs in her possession, both of which are old and miss a tooth or two. 
he also has many purses of different length, in which she carries the combs. 
The only way they fit is horizontally and without overlapping. Given teeth' positions on both combs, 
find the minimum length of the purse she needs to take them with her.

It is guaranteed that there is at least one tooth at each end of the comb.
It is also guaranteed that the total length of two strings is smaller than 32.
Note, that the combs can not be rotated/reversed.

Example

For comb1 = "*..*" and comb2 = "*.*", the output should be
combs(comb1, comb2) = 5.

Although it is possible to place the combs like on the first picture, the best way to do this is either picture 2 or picture 3.



For comb1 = "*...*" and comb2 = "*.*", the output should be
combs(comb1,comb2) = 5;

For comb1 = "*..*..*" and comb2 = "*.*", the output should be
combs(comb1,comb2) = 5;
*/

#include <iostream>

using namespace std;


int combs(string comb1, string comb2)
{
    int saveNode = 0;
    int lenComb1 = comb1.length();
    cout << "len of comb1: " << lenComb1 << endl;
    int lenComb2 = comb2.length();
    cout << "len of comb2: " << lenComb2 << endl;

    // int min = lenComb1 + lenComb2; // min at least

    int compare = 0;
    int comb2Index = 0;
    for (int idex = 1; idex < lenComb1 - 1; idex++)
    {
        cout << "comb1[" << idex << "]: " << comb1[idex] << endl;
        if (comb1[idex] == '*')
        {
            if (idex == lenComb2 - 1 && comb2Index < lenComb2)
                break;
            // if comb2[idex] == '*' 
            if (comb2[comb2Index] == comb1[idex])
            {
                idex = saveNode;
                if (idex == 0)
                    break;
                idex--;
                compare = 0;
                comb2Index = 0;
                if (lenComb1 - idex <= 2)
                {
                    break;
                }
            }
            else
            {
                compare++;
                comb2Index++;
            }
        }
        else
        {
            saveNode = idex;
            compare++;
            comb2Index++;
        }

        cout << "Compare: " << compare << endl;
        if (compare == lenComb2)
        {
            // Least at min equals to maxLen(comb1,comb2);
            cout << "compare equal to lenComb2! <=> " << compare << " - " << lenComb2 << endl;
            return lenComb1;
            compare = 0; // reset compare
        }
    }
    

    if (comb1[lenComb1 - 2] != comb2[0] && comb1[lenComb1 - 1] != comb2[1])
    {
        return lenComb1 + lenComb2 - 2;
    }

    if (comb1[1] != comb2[lenComb2 - 1] && comb1[0] != comb2[lenComb2 - 2])
    {
        return lenComb1 + lenComb2 - 2;
    }

    int count = 0;
    while (comb2[count] == '.')
    {
        count++;
    }

    return lenComb1 + lenComb2 - count;
}


int main()
{
    // cout << combs("*...*", "*.*") << endl;

    // cout << combs("*..*..*", "*.*") << endl;

    // cout << combs("****", "****") << endl;

    // cout << combs("*.**", "*.*") << endl;

    //cout << combs("*.*.*..*", "*.**") << endl;

    // cout << combs("*..***", "*.***") << endl;

    cout << combs("*..*.*", "..***") << endl;

    //             *..*.*
    //                 ..***
    return 0;
}