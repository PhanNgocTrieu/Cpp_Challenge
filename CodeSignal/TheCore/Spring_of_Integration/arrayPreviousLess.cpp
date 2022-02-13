/*
Given array of integers, for each position i, search among the previous positions for the last (from the left) position that contains a smaller value. 
Store this value at position i in the answer. If no such value can be found, store -1 instead.

Example

For items = [3, 5, 2, 4, 5], the output should be
arrayPreviousLess(items) = [-1, 3, -1, 2, 4].
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> arrayPreviousLess(vector<int> items) {
    vector<int> res;
    int len = items.size();
    for (int idex = 0; idex < len; idex++)
    {
        if (idex == 0)   
        {
            res.push_back(-1);
        }
        else
        {
            int flag = 0;
            for (int jdex = idex - 1; jdex >= 0; jdex--)
            {
                if (items[jdex] < items[idex])
                {
                    res.push_back(items[jdex]);
                    flag = 1;
                    break;
                }
            }

            // not found
            if (flag == 0)
                res.push_back(-1);
        }
    }
    return res;
}


int main()
{
    vector<int> items = {3, 5, 2, 4, 5};
    vector<int> res = arrayPreviousLess(items);


    for (int idex = 0; idex < res.size(); idex++)
    {
        cout << res[idex] << " ";
    }
    cout << endl;
    return 0;
}
