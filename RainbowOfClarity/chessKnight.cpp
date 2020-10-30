//Given a position of a knight on the standard chessboard, 
//find the number of different moves the knight can perform.
//
//The knight can move to a square that is two squares horizontallyand one square vertically,
//or two squares vertically and one square horizontally away from it.
//The complete move therefore looks like the letter L.
//Check out the image below to see all valid moves for a knight piece that is placed on one of the central squares.


#include <iostream>
#include <string>


int chessKnight(std::string cell) {
    int moves = 0;
    int posX_cell = int(cell[0]);
    std::cout << "X: " << posX_cell << "\n";
    int posY_cell = int(cell[1]);
    std::cout << "Y: " << posY_cell << "\n";

    // left of x => x = x - 2
    int pre_posX_cell = posX_cell - 2 + posY_cell;

    // checking for pos of (x-2,y)
    if (pre_posX_cell >= (int('a') + posY_cell))
    {
        // checking for pos of (x-2,y+1) 
        int pre_posX_cell_high = posX_cell - 2 + posY_cell + 1;
        if (pre_posX_cell_high <= (posX_cell - 2 + int('8')))
        {
            std::cout << "pre_posX_cell_high: Yes" << "\n";
            moves++;
        }

        // checking for pos of (x-2,y-1) 
        int pre_posX_cell_low = posX_cell - 2 + posY_cell - 1;
        if (pre_posX_cell_low >= (posX_cell - 2 + int('1')))
        {
            std::cout << "pre_posX_cell_low: Yes" << "\n";
            moves++;
        }
    }



    // right of x => x = x + 2
    int next_posX_cell = posX_cell + 2 + posY_cell;
    if (next_posX_cell <= (int('h') + posY_cell))
    {
        // move to the (x+2,y+1)
        int next_posX_cell_high = posX_cell + 2 + posY_cell + 1;
        if (next_posX_cell_high <= (posX_cell + 2 + int('8')))
        {
            std::cout << "next_posX_cell_high: Yes" << "\n";
            moves++;
        }

        // move to the (x+2,y-1)
        int next_posX_cell_low = posX_cell + 2 + posY_cell - 1;
        if (next_posX_cell_low >= (posX_cell + 2 + int('1')))
        {
            std::cout << "next_posX_cell_low: Yes" << "\n";
            moves++;
        }
    }


    // check for (x,y+2)
    int high_posY_cell = posX_cell + posY_cell + 2;
    if (high_posY_cell <= (posX_cell + int('8')))
    {
        // check for (x-1,y+2)
        int high_posY_cell_left = posY_cell + 2 + posX_cell - 1;
        if (high_posY_cell_left >= (int('a') + (posY_cell + 2)))
        {
            std::cout << "high_posY_cell_left: Yes" << "\n";
            moves++;
        }


        // check for (x+1,y+2)
        int high_posY_cell_right = posY_cell + 2 + posX_cell + 1;
        if (high_posY_cell_right <= (int('h') + posY_cell + 2))
        {
            std::cout << "high_posY_cell_right: Yes" << "\n";
            moves++;
        }
    }


    // check for (x, y-2)
    int low_posY_cell = posY_cell - 2 + posX_cell;
    if (low_posY_cell >= (posX_cell + int('1')))
    {
        // check for (x - 1, y - 2)
        int low_posY_cell_left = posY_cell - 2 + posX_cell - 1;
        if (low_posY_cell_left >= (int('a') + posY_cell - 2))
        {
            std::cout << "low_posY_cell_left: Yes" << "\n";
            moves++;
        }


        // check for (x + 1, y - 2)
        int low_posY_cell_right = posY_cell - 2 + posX_cell + 1;
        if (low_posY_cell_right <= (int('h') + posY_cell - 2))
        {
            std::cout << "low_posY_cell_right: Yes" << "\n";
            moves++;
        }

    }
    return moves;
}


int main()
{
    std::string cell = "b5";
    std::cout << chessKnight(cell);
    return 0;
}
