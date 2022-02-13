#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
void countFrequencies(vector<int> arr, const int& _value)
{
    unordered_map<int,int> mp;
    int len = arr.size();

    for (int idex = 0; idex < len; idex++)
    {
        mp[arr[idex]]++;
    }

    for (auto x : mp)
    {
        cout << x.first << " -- " << x.second << endl;
    }

}

int main()
{
    vector<int> arr {1,2,2,3,1,4,22,52,3,2,1,2,2,1,2};
    countFrequencies(arr,2);
    return 0;
}