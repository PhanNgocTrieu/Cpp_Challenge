// Enter A, B!
// 1 <= A,B <= 10^12
// displaying symmetrical numers in range [A;B]

#include <iostream>
#include <math.h>
using namespace std;

long double power(long long int n,long long int k)
{
    if (k == 0)
        return 1;
    long long int i = 1;
    long double mul = 1;
    while (i <= k)
    {
        mul = mul * n;
        i++;
    }
    return mul;
}

bool checkDX(long long int n)
{
    int arr[50];
    int i = 0;
    while (n > 0)
    {
        arr[i] = n % 10;
        n = n / 10;
        i++;
    }
    

    int left = 0;
    int right = i - 1;
    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;

    }
    return true;       
}

int main()
{
    long long int A;
    long long int B;
    do
    {
        cout << "Nhap A: ";
        cin >> A;
        cout << "Nhap B: ";
        cin >> B;
    } while (A < 1 || A > power(12,10) || B < 1 || B > power(12,10) || A > B);
    
	for (long long int i = A; i <= B; i ++)
	{
		if (checkDX(i) == true)
		{
			cout << i << " -> DX" << endl;
		}
	}
	// your code goes here
	return 0;
}
