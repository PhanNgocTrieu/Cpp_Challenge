// Given a rectangular matrix containing only digits, calculate the number of different 2 × 2 squares in it.

// Example

// For
 
// matrix = [[1, 2, 1],
//           [2, 2, 2],
//           [2, 2, 2],
//           [1, 2, 3],
//           [2, 2, 1]]
// the output should be
// differentSquares(matrix) = 6.

// Here are all 6 different 2 × 2 squares:

// 1 2
// 2 2
// 2 1
// 2 2
// 2 2
// 2 2
// 2 2
// 1 2
// 2 2
// 2 3
// 2 3
// 2 1


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

std::string Encode(int top_left, int top_right, int bot_left, int bot_right)
{
    std::cout << "Top Left: " << top_left << ", Top Right: " << top_right << ", Bot Left: " << bot_left << ", Bot Right: " << bot_right << "\n";
    
    std::cout << (to_string(top_left)+to_string(top_right)+to_string(bot_left)+to_string(bot_right)) << "\n";
    return (to_string(top_left)+to_string(top_right)+to_string(bot_left)+to_string(bot_right));    
}
std::string get2x2Window(std::vector<vector<int>> matrix, int xPos, int yPos)
{
    return Encode(matrix[xPos][yPos],matrix[xPos+1][yPos],matrix[xPos][yPos+1],matrix[xPos+1][yPos+1]);
}


int differentSquares(vector<vector<int>> matrix) {
    // 0. Create a hashset
    std::set<string> squareTracker;
    int ht = matrix.size();
    int wd = matrix[0].size();
    // 1. iterate left to right and up to down
    for (int up_to_down = 0; up_to_down < ht - 1; up_to_down++)
    {
        for (int lef_to_rig = 0; lef_to_rig < wd - 1; lef_to_rig++)
        {
            squareTracker.insert(get2x2Window(matrix,up_to_down,lef_to_rig));
        }
    }
    return squareTracker.size();
    // 2. capture 2x2 window of data from matrix -- String?
    //  2.1 encode it as a string val for adding into hashset
    // 3. Return size of harshset == number of diff sq
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
    std::cout <<  "\n" << differentSquares(matrix);
    return 0;
}
