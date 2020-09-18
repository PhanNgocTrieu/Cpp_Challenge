//Given two cells on the standard chess board, 
//determine whether they have the same color or not.
//
//Example
//
//For cell1 = "A1" and cell2 = "C3", the output should be
//chessBoardCellColor(cell1, cell2) = true.
//
//
//
//For cell1 = "A1" and cell2 = "H3", the output should be
//chessBoardCellColor(cell1, cell2) = false.

#include <iostream>
#include <string>

int int_cell(std::string cell)
{
	int n = cell.length();
	int int_cell_res = 0;
	for (int i = 0; i < n; i++)
	{
		int_cell_res += (int)cell[i];
	}
	return int_cell_res;
}

bool chessBoardCellColor(std::string cell1, std::string cell2) {

	int int_cell1 = int_cell(cell1);
	int int_cell2 = int_cell(cell2);

	if ( (int_cell1 % 2 != 0 && int_cell2 % 2 != 0) || (int_cell1 % 2 == 0 && int_cell2 % 2 == 0))
	{
		return true;
	}
	return false;
}

int main()
{
	std::string cell1 = "H3";
	std::string cell2 = "A1";
	//std::cout << int_cell(cell1) << std::endl;
	if (chessBoardCellColor(cell1,cell2) == true)
	{
		std::cout << "True!" << std::endl;
	}
	else
	{
		std::cout << "False!" << std::endl;
	}
	return 0;
}

