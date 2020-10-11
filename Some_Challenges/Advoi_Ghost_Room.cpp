/*After becoming famous, the CodeBots decided to move into a new building together. 
Each of the rooms has a different cost, and some of them are free, but there's a rumour that 
all the free rooms are haunted! Since the CodeBots are quite superstitious, 
they refuse to stay in any of the free rooms, or any of the rooms below any of the free rooms.

Given matrix, a rectangular matrix of integers, where each value represents the cost of the room,
your task is to return the total sum of all rooms that are suitable for the CodeBots 
(ie: add up all the values that don't appear below a 0).

Example:
matrix = [[0, 1, 1, 2],
		  [0, 5, 0, 0],
		  [2, 0, 3, 3]]
the output should be
matrixElementsSum(matrix) = 9.
There are several haunted rooms, 
so we'll disregard them as well as any rooms beneath them. Thus, the answer is 1 + 5 + 1 + 2 = 9.


*/

#include <iostream>
#include <vector>

int matrixElementsSum(std::vector<std::vector<int>> matrix) {
	
	int sum = 0;
	std::vector<int> zero_cols;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				zero_cols.push_back(j);
			}
			else
			{
				bool IsExist = false;
				for (int a = 0; a < zero_cols.size(); a++)
				{
					if (j == zero_cols[a])
					{
						IsExist = true;
					}
				}

				if (IsExist == false)
				{
					sum += matrix[i][j];
				}
			}

		}
	}

	return sum;
}

int main()
{
	std::vector<std::vector<int>> matrix = { {0,1,1,2},
	{1,5,0,0},
	{1,0,2,1}
	};

	std::cout << matrixElementsSum(matrix);
	return 0;
}
