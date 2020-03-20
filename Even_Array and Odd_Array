Viết chương trình nhập vào một dãy các số nguyên từ bàn phím và lưu vào mảng một chiều,
so sánh tổng các phần tử chẵn với tổng các phần tử lẻ và đưa ra màn hình kết quả.

-----------------------------------------Solution-----------------------------------------------

#include <iostream>
#include <cstdlib> // using Halt by function: exit();
#include <ctime> //using void srand(unsing int seed);
#include <time.h> //using time();
using namespace std;


void Enter_Arr(int32_t e_arr[100], int32_t b) {

	for (int32_t i = 0; i < b; i++)
	{
		cout << "[" << i << "] = ";
		cin >> e_arr[i];
	}

}

int32_t Even_total(int32_t e_t_arr[100], int32_t b) {

	int32_t sum_even = 0;
	for (int32_t i = 0; i < b; i++)
	{
		if (e_t_arr[i]%2==0)
		{
			sum_even += e_t_arr[i];
		}
	}

	return sum_even;
}

int32_t odd_total(int32_t e_t_arr[100], int32_t b) {

	int32_t sum_odd = 0;
	for (int32_t i = 0; i < b; i++)
	{
		if (e_t_arr[i] % 2 != 0)
		{
			sum_odd += e_t_arr[i];
		}
	}

	return sum_odd;
}



int main() {

	int32_t Arr[100];
	int32_t size;
	cout << "Enter size of arr: "; cin >> size;

	Enter_Arr(Arr, size);
	Even_total(Arr, size);
	odd_total(Arr, size);
	

	cout << "Sum of even_array: " << Even_total(Arr, size);
	cout << endl;
	cout << "Sum of odd_array: " << odd_total(Arr, size);
	cout << endl;

	if (Even_total(Arr,size) > odd_total(Arr,size))
	{
		
		cout << "Even Array is bigger than Odd Array:";
	}
	else if (Even_total(Arr, size) < odd_total(Arr, size))
	{
		cout << "Odd Array is bigger than Even Array";
	}
	else
	{
		cout << "both is equal";
	}

	return 0;
}
