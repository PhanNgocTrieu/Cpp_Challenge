#include <iostream>
#include <ctime>

#define MAX_ROW 100
#define MAX_COL 100

bool checkingElement(int arr[][MAX_COL], int row, int col)
{
	return arr[row][col] == 1 ? true : false;
}

void enterArray(int arr[MAX_ROW][MAX_COL], int rows, int cols)
{
	// set the seed
	srand(time(NULL));

	
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			arr[r][c] = rand() % 2 + 0;
		}
	}	
}

bool checking(int arr[][MAX_COL], int row, int col, int max_row, int max_col)
{
	if (arr[row][col] == 1)
	{
		arr[row][col] = 0;

		// checking for arr[i+1][j]
		if ( (row + 1) < max_row && checkingElement(arr,row+1,col) == true)
		{
			checking(arr, row + 1, col, max_row, max_col);
		}


		// checking for arr[i][j+1]
		if ( (col + 1) < max_col  && checkingElement(arr,row,col+1) == true)
		{
			checking(arr, row, col + 1, max_row, max_col);
		}

		// checking for arr[i-1][j]
		if ( row - 1 >= 0 && checkingElement(arr,row - 1,col) == true)
		{
			checking(arr, row - 1, col, max_row, max_col);
		}

		// checking for arr[i][j-1]
		if (col - 1 >= 0 && checkingElement(arr,row, col-1) == true)
		{
			checking(arr, row, col - 1, max_row, max_col);
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

void printArray(int arr[MAX_ROW][MAX_COL], int rows, int cols)
{
	// set the seed
	srand(time(NULL));
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			std::cout << arr[r][c] << " ";
		}
		std::cout << "\n";
	}
}

int island(int arr[][MAX_COL], int rows, int cols)
{
	int count = 0;
	
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (checking(arr, r, c, rows, cols))
				count++;
		}
	}

	return count;
}

int main()
{
	int arr[MAX_ROW][MAX_COL];

	int rows, cols;

	std::cout << "Enter rows and cols you want: ";
	std::cin >> rows >> cols;

	enterArray(arr, rows, cols);
	printArray(arr, rows, cols);

	std::cout << "count: " << island(arr, rows, cols) << "\n";

	//printArray(arr, rows, cols);

	getchar();
	getchar();
	return 0;
}