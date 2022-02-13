#include <iostream>
#include <vector>
#include <numeric> // using accumulate
using namespace std;


double sumOfElems(vector<double> arr)
{
    int len = arr.size();
    double sum = 0;
    for (int idex = 0; idex < len; idex++)
    {
        sum += arr[idex];
    }
    return sum;
}

int main()
{
    vector<double> arr {1,3,2.1,3,4,2.12,32.421,231,23};
    // using defined function
    cout << "Sum of elems: " << sumOfElems(arr) << endl;

    // using library
    double sum = 0;
    cout << "(STL) Sum of elems: " << accumulate(arr.begin(),arr.end(),sum) << endl;
    return 0;
}