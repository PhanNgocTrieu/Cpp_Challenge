#include <iostream>

using namespace std;

int maxValue(const int* _a, int _size)
{
    int max = _a[0];

    for (int i = 1; i < _size; i++)
    {
        if (_a[i] > max)
            max = _a[i];
    }

    return max;
}

int main()
{
    int _testCase;
    int* A;
    int* B;

    cin >> _testCase;

    for (int i = 0; i < _testCase; i++)
    {
        int _elemOfArray;
        cin >> _elemOfArray;

        A = new int[_elemOfArray];
        B = new int[_elemOfArray];

        for (int j = 0; j < _elemOfArray; j++)
        {
            cin >> A[j];
        }

        for (int j = 0; j < _elemOfArray; j++)
        {
            cin >> B[j];
        }
        
        cout << maxValue(A,_elemOfArray) * maxValue(B,_elemOfArray) << std::endl;
    }

    return 0;
}