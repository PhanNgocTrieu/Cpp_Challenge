/*
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that each column, each row,
and each of the nine 3 × 3 sub-grids that compose the grid contains all of the digits from 1 to 9.

This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

Example

For
grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
        [4, 6, 5, 8, 7, 9, 3, 2, 1],
        [7, 9, 8, 2, 1, 3, 6, 5, 4],
        [9, 2, 1, 4, 3, 5, 8, 7, 6],
        [3, 5, 4, 7, 6, 8, 2, 1, 9],
        [6, 8, 7, 1, 9, 2, 5, 4, 3],
        [5, 7, 6, 9, 8, 1, 4, 3, 2],
        [2, 4, 3, 6, 5, 7, 1, 9, 8],
        [8, 1, 9, 3, 2, 4, 7, 6, 5]]
the output should be
sudoku(grid) = true;
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// checking rows;

bool checkRows(vector<vector<int>> grid)
{
    //checking for each of rows:
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> track;
        // go through each element in a row
        for (int j = 0; j < grid[0]
        .size(); j++)
        {
            if (track.empty())
            {
                track.push_back(grid[i][j]);
            }
            else
            {
                // if found
                if (find(track.begin(),track.end(),grid[i][j]) != track.end())
                {
                    return false;
                }
                track.push_back(grid[i][j]);
            }
        }
    }
    return true;
}


// checking cols:

bool checkCols(vector<vector<int>> grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    for (int cols_index = 0; cols_index < cols; cols_index++)
    {
        vector<int> track;
        for (int rows_index = 0; rows_index < rows; rows_index++)
        {
            if (track.empty())
            {
                track.push_back(grid[rows_index][cols_index]);
            }
            else
            {
                if (find(track.begin(),track.end(),grid[rows_index][cols_index]) != track.end())
                {
                    return false;
                }
                track.push_back(grid[rows_index][cols_index]);
            }
            
            
        }
        
    }
    return true;
}

// Split Matrix 3x3:
vector<vector<int>> sub_grid(vector<vector<int>> grid, int start_r, int end_r, int start_c, int end_c)
{
    int temp_start_r = start_r;
    vector<vector<int>> res_sub_grid(3,vector<int>(3,0));
    for(int i = 0; i < 3; i++)
    {
        int temp_start_c = start_c;
        for (int j = 0; j < 3; j++)
        {
            res_sub_grid[i][j] = grid[temp_start_r][temp_start_c];
            //cout << "\n" << temp_start_c << " ";
            temp_start_c++;
        }
        temp_start_r++;
    }
    return res_sub_grid;
}

//checking matrix
bool check_Matrix(vector<vector<int>> sub_grid_check)
{
    vector<int> track;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (track.empty())
            {
                track.push_back(sub_grid_check[i][j]);
            }
            else
            {
                // if not found
                if(find(track.begin(),track.end(),sub_grid_check[i][j]) == track.end())
                {
                    track.push_back(sub_grid_check[i][j]);
                }
                else //found
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool sudoku(vector<vector<int>> grid) {
    int end_r = grid.size();
    int end_c = grid[0].size();
    vector<int> track;
    //checking for rows:
    if (checkRows(grid) == false)
    {
        return false;
    }

    //checking for cols:

    if(checkCols(grid) == false)
    {
        return false;
    }

    //checking for 3x3 matrix:
    for (int start_r = 0; start_r < end_r - 3; start_r = start_r + 3)
    {
        for (int start_c = 0; start_c < end_c - 3; start_c = start_c + 3)
        {
            if(check_Matrix(sub_grid(grid,start_r,start_r+3,start_c,start_c+3)) == false)
            {
                return false;
            }
            // vector<vector<int>> sub_matrix = sub_grid(grid,start_r,start_r+3,start_c,start_c+3);
            // for (int i = 0; i < sub_matrix.size(); i++)
            // {
            //     for (int j = 0; j < sub_matrix[0].size(); j++)
            //     {
            //         cout << sub_matrix[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // break;
        }   
        // break;
    }
    return true;
}

int main()
{
    vector<vector<vector<int>>> three_vector;

    vector<vector<int>> grid = {
        {1, 3, 2, 5, 4, 6, 9, 8, 7},
        {4, 6, 5, 8, 7, 9, 3, 2, 1},
        {7, 9, 8, 2, 1, 3, 6, 5, 4},
        {9, 2, 1, 4, 3, 5, 8, 7, 6},
        {3, 5, 4, 7, 6, 8, 2, 1, 9},
        {6, 8, 7, 1, 9, 2, 5, 4, 3},
        {5, 7, 6, 9, 8, 1, 4, 3, 2},
        {2, 4, 3, 6, 5, 7, 1, 9, 8},
        {8, 1, 9, 3, 2, 4, 7, 6, 5}
        };

    if(sudoku(grid))
    {
        cout << "True!\n";
    }
    else
    {
        cout << "False!\n";
    }
    

    return 0;
}