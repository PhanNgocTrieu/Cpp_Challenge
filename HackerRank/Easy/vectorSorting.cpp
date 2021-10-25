/**
 * @file vectorSorting.cpp
 * @author trieu john (phantrieu580@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // For running in submitting
    vector<int> v;
    int _size;
    cin >> _size;
    for (int i = 0; i < _size; i++)
    {
        int _var;
        cin >> _var;
        v.push_back(_var);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < _size; i++)
    {
        cout << v[i] << " ";
    }


    /**
     * @brief For running in vscode for testing
     * 
     */
    // vector<int> v = {1,3,5,2,8,9,10};
    // int _size = v.size();
    // cin >> _size;
    // for (int i = 0; i < _size; i++)
    // {
    //     int _var;
    //     cin >> _var;
    //     v.push_back(_var);
    // }
    
    // sort(v.begin(), v.end());
    
    // for (int i = 0; i < _size; i++)
    // {
    //     cout << v[i] << " ";
    // }
    
    return 0;
}
