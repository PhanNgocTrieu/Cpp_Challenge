#include "../include/arrayProblems.h"

vector<int> ArrayProblems::reverseArray(vector<int> a) {
    vector<int> reverseArray;
    for (vector<int>::iterator itr = a.end() - 1; itr != a.begin() - 1; itr--)
    {
        reverseArray.push_back(*itr);
    }
    
    return reverseArray;
}
