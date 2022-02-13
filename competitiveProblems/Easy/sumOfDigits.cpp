#include <iostream>

using namespace std;

int sumOfDigits(string x)
{
    int res = 0;
    int len = x.length();
    for (int idex = 0; idex < len; idex++)
    {
        res += x[idex] - '0';
    }
    return res;
}
int main()
{
    cout << sumOfDigits("33213213") << endl;
    return 0;
}