//	In the popular Minesweeper game you have a board with some minesand 
//	those cells that don't contain a mine have a number in it that indicates 
//	the total number of mines in the neighboring cells. Starting off with some arrangement of mines
//	we want to create a Minesweeper game setup.
//
//	Example
//
//	For
//
//	matrix = [
//	[true, false, false],
//	[false, true, false],
//	[false, false, false]]
//	the output should be
//
//	minesweeper(matrix) = [[1, 2, 1],
//	[2, 1, 1],
//	[1, 1, 1]]

// Cpp we could not check undefined so to do the basic way! we need to check all of element! And we have so special postion that we could not check arround (8 element)
// So we need to check position (x,y) = (0,0), (0, matrix[i].size() - 1), (0, 0 < y < matrix[i].size() - 1);
// And position (x,y) = (matrix.size() - 1,0), (matrix.size() - 1, matrix[i].size() - 1), (matrix.size() - 1, 0 < y < matrix[i].size() - 1);
// else position (x,y) = (0 < x < matrix.size() - 1, 0), (0 < x < matrix.size() - 1, matrix[i].size() - 1), (0 < x < matrix.size() - 1, 0 < y < matrix[i].size() - 1)


#include <iostream>
#include <vector>

std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
	std::vector<std::vector<int>> matrix_output;
	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<int> temp;
		int i_up = i + 1;
		int i_down = i - 1;
		for (int j = 0; j < matrix[i].size(); j++)
		{
			int j_up = j + 1;
			int j_down = j - 1;
			int n = 0;
			if (i == 0)
			{
				if (j == 0)   // x = 0 && y = 0
				{
					if (matrix[i][j_up] == true) n++;
					if (matrix[i_up][j] == true) n++;
					if (matrix[i_up][j_up] == true) n++;
				}
				else if (j == matrix[i].size() - 1)  // x = 0 && y = matrix[i].size() - 1
				{
					if (matrix[i][j_down] == true) n++;
					if (matrix[i_up][j_down] == true) n++;
					if (matrix[i_up][j] == true) n++;
				}
				else   // x = 0 && (0 < y < matrix[i].size() - 1) 
				{
					if (matrix[i][j_down] == true) n++;
					if (matrix[i][j_up] == true) n++;
					if (matrix[i_up][j_down] == true) n++;
					if (matrix[i_up][j] == true) n++;
					if (matrix[i_up][j_up] == true) n++;
				}
			}
			else if (i == matrix.size() - 1) // x == matrix.size() - 1
			{
				if (j == 0) // y = 0
				{
					if (matrix[i_down][j] == true) n++;
					if (matrix[i_down][j_up] == true) n++;
					if (matrix[i][j_up] == true) n++;
				}
				else if (j == matrix[i].size() - 1) // y = matrix[i].size() - 1)
				{
					if (matrix[i][j_down] == true) n++;
					if (matrix[i_down][j_down] == true) n++;
					if (matrix[i_down][j] == true) n++;
				}
				else // y = 0 < y < matrix[i].size() - 1
				{
					if (matrix[i][j_down] == true) n++;
					if (matrix[i][j_up] == true) n++;
					if (matrix[i_down][j_down] == true) n++;
					if (matrix[i_down][j] == true) n++;
					if (matrix[i_down][j_up] == true) n++;
				}
			}
			else  // x  = 0 < x < matrix.size() - 1 
			{
				if (j == 0) // y = 0
				{
					if (matrix[i_down][j] == true) n++;
					if (matrix[i_up][j] == true) n++;
					if (matrix[i_down][j_up] == true) n++;
					if (matrix[i][j_up] == true) n++;
					if (matrix[i_up][j_up] == true) n++;
				}
				else if (j == matrix[i].size() - 1) // y = matrix[i].size() - 1)
				{
					if (matrix[i_down][j] == true) n++;
					if (matrix[i_down][j_down] == true) n++;
					if (matrix[i][j_down] == true) n++;
					if (matrix[i_up][j_down] == true) n++;
					if (matrix[i_up][j] == true) n++;
				}
				else  // y =  0 < y < matrix[i].size() - 1
				{
					if (matrix[i][j_down] == true) n++; 
					if (matrix[i][j_up] == true) n++;
					if (matrix[i_down][j_down] == true) n++;
					if (matrix[i_down][j] == true) n++;
					if (matrix[i_down][j_up] == true) n++;
					if (matrix[i_up][j_down] == true) n++;
					if (matrix[i_up][j] == true) n++;
					if (matrix[i_up][j_up] == true) n++;
				}
			}
			temp.push_back(n);
			std::cout << i << " : " << j << std::endl;
		}
		matrix_output.push_back(temp);
	}
	return matrix_output;
}

// drive function
int main()
{
	std::vector<std::vector<bool>> matrix = {
		{true, false, false},
		{false, true, false},
		{false, false, false}
	};
	std::vector<std::vector<int>> temp =  minesweeper(matrix);
	std::cout << "This following is a Minesweeper!" << std::endl;
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			std::cout << temp[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
