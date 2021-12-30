#include "../include/arrayProblems.h"

vector<int> ArrayProblems::reverseArray(vector<int> a) {
    vector<int> reverseArray;
    for (vector<int>::iterator itr = a.end() - 1; itr != a.begin() - 1; itr--)
    {
        reverseArray.push_back(*itr);
    }
    m_vector = reverseArray;
    printArray();
    return reverseArray;
}


vector<int> ArrayProblems::dynamicArray(int n, vector<vector<int>> queries) {
    
}



void ArrayProblems::printArray()
{
    for (vector<int>::iterator it = m_vector.begin(); it != m_vector.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}