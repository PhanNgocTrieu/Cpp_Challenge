// Viết chương trình tìm kiếm sự xuất hiện của giá trị X nhập từ bàn phím trong mảng hai chiều.




#include <iostream>

#define Max_Size 20
using namespace std;
void Input(float A[Max_Size][Max_Size], int32_t a) {
	for (int32_t index_1 = 0; index_1 < a; index_1++)
	{
		for (int32_t index_2 = 0; index_2 < a; index_2++)
		{
			cout << "Array[" << index_1 << "][" << index_2 << "]: ";
			cin >> A[index_1][index_2];
			cout << endl;
		}
	}
}


bool Check_X(float B[Max_Size][Max_Size], int32_t b, float c) {
	for (int32_t index_1 = 0; index_1 < b; index_1++)
	{
		for (int32_t index_2 = 0; index_2 < b; index_2++)
		{
			if (B[index_1][index_2] == c)
			{
				return true;
			}
			else
			{
				return false;
			}
		}	

	}
}
int main() {
	float Arr[Max_Size][Max_Size];
	int32_t size;
	float X;
	cout << "Enter size: ";
	cin >> size;
	cout << endl;
	Input(Arr,size);
	cout << "Enter X: ";
	cin >> X;
	Check_X(Arr,size,X);
	cout << endl;
	if (Check_X)
	{
		cout << "X exists in Arr" << endl;
	}
	else
	{
		cout << "X does not exist in Arr" << endl;
	}
	return 0;
}
