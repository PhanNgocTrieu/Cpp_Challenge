/*
Yesterday you found some shoes in the back of your closet. Each shoe is described by two values:

    type indicates if it's a left or a right shoe;
    size is the size of the shoe.

Your task is to check whether it is possible to pair the shoes you found in such a way that 
each pair consists of a right and a left shoe of an equal size.

Example

    For

    shoes = {0, 21}, 
             {1, 23}, 
             {1, 21}, 
             {0, 23}}

    the output should be
    pairOfShoes(shoes) = true;

    For

    shoes = {{0, 21}, 
             {1, 23}, 
             {1, 21}, 
             {1, 23}}

    the output should be
    pairOfShoes(shoes) = false
*/

#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

/*
 vector<vector<int>> items = {{0, 21}, 
             {1, 23}, 
             {1, 21}, 
             {0, 23}};

    if (type == 0)
        arrCount[pos]--;
    if (type == 1)
        arrCount[pos]++;

    arrValue = {21 ,  23};
    arrCount = {n_21, n_23};

    => Return: true if no elem in arrCount != 0; false otherwise;
*/
int findValue(vector<int> vec, int _value)
{
    int len = vec.size();
    for (int idex = 0; idex < len; idex++)
    {
        if (vec[idex] == _value)
            return idex;
    }
    return -1;
}

bool pairOfShoes(vector<vector<int>> shoes) 
{
    int len = shoes.size();
    vector<int> arrValue;
    vector<int> arrCount;
    for (int idex = 0; idex < len; idex++)
    {
        if (arrValue.empty())
        {
            arrValue.push_back(shoes[idex][1]);
            if (shoes[idex][0] == 1)
            {
                arrCount.push_back(1);
            }
            else
            {
                arrCount.push_back(-1);
                
            }
        }
        else
        {
            int pos = findValue(arrValue, shoes[idex][1]);
            if ( pos == -1)
            {
                arrValue.push_back(shoes[idex][1]);
                if (shoes[idex][0] == 1)
                {
                    arrCount.push_back(1);
                }
                else
                {
                    arrCount.push_back(-1);
                }
            }
            else
            {
                if (shoes[idex][0] == 1)
                {
                    arrCount[pos]++;
                }
                else
                {
                    arrCount[pos]--;
                }
                
            }
        }
    }
    int len_count = arrCount.size();

    // Print Reference for checking
    for (int idex = 0; idex < arrValue.size(); idex++)
    {
        cout << arrValue[idex] << " ";
    }
    cout << endl;
    
    for (int idex = 0; idex < len_count; idex++)
    {
        cout << arrCount[idex] << " ";
    }
    cout << endl;

    // Checking Count:
    for (int idex = 0; idex < len_count; idex++)
    {
        if (arrCount[idex] != 0)
            return false;
    }

    return true;
}


int main()
{
    vector<vector<int>> items = {{0, 21}, 
             {1, 23}, 
             {1, 21}, 
             {0, 23}};

    vector<vector<int>> items2 = {
                                {1,25}, 
                                {0,100}, 
                                {1,1}, 
                                {1,1}, 
                                {0,25}, 
                                {0,1}, 
                                {0,100}, 
                                {1,1}, 
                                {1,100}, 
                                {0,25}, 
                                {0,1}, 
                                {1,1}, 
                                {0,100}, 
                                {1,25}, 
                                {0,1}
                                };


    if (bool res = pairOfShoes(items))
    {
        cout << "True!" << endl;
    }
    else
        cout << "False!" << endl;   

    if (bool res = pairOfShoes(items2))
    {
        cout << "True!" << endl;
    }
    else
        cout << "False!" << endl;

    
    cout << endl;
    return 0;
}
