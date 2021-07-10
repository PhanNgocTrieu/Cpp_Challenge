
3/ Viết chương trình in ra tất cả các phần tử của mảng nhưng bỏ qua các giá trị bị trùng lặp. Ví dụ với mảng một chiều như sau:

4 6 2 2 1 6 9

Kết quả in ra màn hình sẽ là:

4 6 2 1 9




---------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib> // using Halt by function: exit();   //no need
#include <ctime> //using void srand(unsing int seed);   //no need
#include <time.h> //using time();    // no need

using namespace std;

void Cin_Array(int32_t A[100], int a) {

	for (int32_t index = 0; index < a; index++)
	{
		cin >> A[index];
		cout << endl;
	}
}

void Cout_Array(int32_t B[100], int b) {

	

	for (int32_t index = 0; index < b; index++)
	{
		int32_t temp = 0;
		for (int32_t index_2 = 0; index_2 < index; index_2++)
		{
			if (B[index] == B[index_2]) {
				temp += 1;
			}
		}

		if (temp == 0)
		{
			cout << B[index] << " ";
		}

	}
}

int main() {

	int32_t arr[100];
	int32_t limit_array;

	cout << "Enter limit_array: ";
	cin >> limit_array;

	Cin_Array(arr, limit_array);
	Cout_Array(arr, limit_array);

	return 0;
}
