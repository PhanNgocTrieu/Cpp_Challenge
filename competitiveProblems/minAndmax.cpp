#include <iostream>
#include <vector>

using namespace std;

// O(n)
void findMaxMinLinear(vector<int> arr)
{
    int len = arr.size();
    int min = INT32_MAX;
    int max = INT32_MIN;

    for (int idex = 0; idex < len; idex++)
    {
        if (arr[idex] > max)
            max = arr[idex];
        if (arr[idex] < min)
            min = arr[idex];
    }

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

// Reducing comparisons:
// Source: from GeeksforGeeks
struct Pair
{
    int min;
    int max;
};
struct Pair getMinMax(int arr[], int low,
                      int high)
{
    struct Pair minmax, mml, mmr;
    int mid;

    // If there is only one element
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than 2 elements
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);

    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;

    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;

    return minmax;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 71, 23, 21, 231, 212, 11, 211};
    findMaxMinLinear(arr);
    return 0;
}