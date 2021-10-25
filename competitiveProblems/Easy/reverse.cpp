#include <iostream>
#include <vector>
using namespace std;

// Reversing Array or String

void Reverse(vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}


int main()
{
    vector<int> arr = {1,3,25,6,5,3,1,2,4,2};
    Reverse(arr);
    int len = arr.size();
    for (int idex = 0; idex < len; idex++)
    {
        cout << arr[idex] << " ";
    }
    cout << endl;
    return 0;
}