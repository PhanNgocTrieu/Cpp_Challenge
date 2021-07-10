/*Given a rectangular matrix containing only digits, calculate the number of different 2 × 2 squares in it.*/

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int differentSquares(vector<vector<int>> matrix) {

	int ROW = matrix.size() - 1;
	int COL = matrix[0].size() - 1;
	
	set<string> square_set;
	
	for (int rows = 0; rows < ROW; rows++)
	{
		for (int cols = 0; cols < COL; cols++)
		{
			string temp = to_string(matrix[rows][cols]) + to_string(matrix[rows + 1][cols]) + to_string(matrix[rows][cols + 1]) + to_string(matrix[rows + 1][cols + 1]);
			square_set.insert(temp);
		}
	}

	return square_set.size();
}


int main()
{
	vector<vector<int>> matrix = {
		{1,2,1},
		{2,2,2},
		{2,2,2},
		{1,2,3},
		{2,2,1}
	};
	cout << differentSquares(matrix);
	return 0;
}
