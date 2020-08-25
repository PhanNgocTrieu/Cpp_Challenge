#include <iostream>
#include <time.h> // compute CPU time!
#include <math.h>

using namespace std;

bool CheckPrime(long long int n)
{
    long long int max = n / 2;
    if (n == 1 || n == 0)
        return false;
    for (long long int i = 2; i <= max; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool CheckSpecialPrime(long long int n)
{
    bool isSpecialPrime = true;
    if (n == 0 || n == 1)
    {
        return false;
    }
    while (n > 0)
    {
        if (CheckPrime(n) != true)
        {
            isSpecialPrime = false;
            return isSpecialPrime;
        }
        n = n / 10;
    }
    return isSpecialPrime;
}
int main()
{
    clock_t start, end;
    double cpu_time_used;
    long long int n;
    do
    {
        cout << "Nhap n: ";
        cin >> n;
    } while (n < 0 && n > pow(10,7));
    start = clock();
    
    // Checking
    // cout << "======LIST OF Special Prime Number!! =========" << endl;
    // for (long long int i = 0; i <= n; i++)
    // {
    //     if (CheckSpecialPrime(i) == true)
    //     {
    //         cout << i << " -> This is a special prime!" << endl;
    //     }
    // }

    if (CheckSpecialPrime(n) == true)
    {
        cout << n << " -> True" << endl;
    }
    else
    {
        cout << n << " -> False" << endl;
    }
    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    cout << "CPU time: " << (double)cpu_time_used << endl;
    return 0;
}
