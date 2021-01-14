// Construct a square matrix with a size N × N containing integers from 1 to N * N in a spiral order,
// starting from top-left and in clockwise direction.
// Example:
// For n = 3, the output should be
// spiralNumbers(n) = [[1, 2, 3],
//                     [8, 9, 4],
//                     [7, 6, 5]]


//----------------------------------------------------------------------------------------------------


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralNumbers(int n)
{
	vector<vector<int>> res;
	int cols = 0;
	int rows = 0;
	int num = 1;
	
	while (rows < n && cols <= n)
	{
		// n = 4
		for (int i = cols; i < n; i++)
		{
			res[rows][i] = num;
			num++;
		}
		rows++;
		// rows = 1
		for (int i = rows; i < n; i++)
		{
			res[i][n - 1] = num;
			num++;
		}
		n--;
		// n = 3
		if (cols < n)
		{
			for	(int i = n - 1; i >= cols; i--) // cols == 0
			{
				res[n][i] = num;
				num++;
			}
		}
		
		if (rows < n)
		{
			for (int i = n - 1; i >= rows; i++)
			{
				res[i][cols] = num;
				num++;
			}
		}
		cols++;
	}
	return res;
}

int main() {
	
	// your code goes here
	spiralNumbers(4);
	return 0;
}
