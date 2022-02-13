#include <iostream>
#include <cstdlib> // using Halt by function: exit();
#include <ctime> //using void srand(unsing int seed);
#include <time.h> //using time();
using namespace std;


int main() {

	int32_t arr[] = { 2,6,5,7,9,1,3 };
	const int32_t N = sizeof(arr) / sizeof(int32_t);
	int32_t arr_2[6];
	int32_t temp = 0, up=0;

	do
	{
		temp = arr[up];
		arr[up] = arr[N - 1 - up];
		arr[N - 1 - up] = temp;
		up++;
	} while (up < (N-1)/2);

	for (int32_t i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;

}
