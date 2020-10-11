#include <iostream>
using namespace std;
void Input_Arr(float A[50][50], int32_t c, int32_t d) {
	for (int32_t i = 0; i < c; i++)
	{
		for (int32_t j = 0; j < d; j++)
		{
			cout << "Array[" << i << "][" << j << "]: ";
			cin >> A[i][j];
			cout << "\n";
		}

	}
}

void delete_cols(float B[50][50], int32_t f, int32_t g, int32_t h) {

	if (h > g)
	{
		cout << "Array doesn't change";
	}
	else
	{
		for (int32_t i = 0; i < f; i++)
		{
			for (int32_t j = h; j < g - 1; j++)
			{
				B[i][j] = B[i][j + 1];
			}
			
		}
	}
}
void Output_deleted_Array(float C[50][50], int32_t k, int32_t l) {

	for (int32_t i = 0; i < k; i++)
	{
		for (int32_t j = 0; j < l - 1; j++)
		{

			cout << C[i][j] << " ";
		}

		cout << "\n";
	}

}
int main() {
	float Array[50][50];
	int32_t num_of_row;
	int32_t num_of_col;
	int32_t deleted_cols;

	cout << "Enter number of row: "; cin >> num_of_row;
	cout << "\nEnter number of col: "; cin >> num_of_col;

	Input_Arr(Array, num_of_row, num_of_col);

	cout << "Enter Col which you wants to delete: ";
	cin >> deleted_cols;

	// Enter_del_col_number(deleted_cols);

	delete_cols(Array, num_of_row, num_of_col, deleted_cols);
	Output_deleted_Array(Array, num_of_row, num_of_col);


	return 0;
}
