//Given the positions of a white bishopand a black pawn on the standard chess board, 
//determine whether the bishop can capture the pawn in one move.
//
//The bishop has no restrictions in distance for each move, 
//but is limited to diagonal movement.Check out the example below to see how it can move :

#include <iostream>
#include <string>


bool bishopAndPawn(std::string bishop, std::string pawn) {
   
    int Pos_Bishop = (int)(bishop[0] + (int)bishop[1]);
    int Pos_Pawn = (int)(pawn[0] + pawn[1]);
    // in the main Diagonal
    if (Pos_Bishop == Pos_Pawn)
    {
        return true;
    }
    // in the sub-Diagonal

    Pos_Bishop = (int)(bishop[0] - bishop[1]);
    Pos_Pawn = (int)(pawn[0] - pawn[1]);
    if (Pos_Bishop == Pos_Pawn)
        return true;
    return false;

}


int main()
{
	if (bishopAndPawn("h1", "h3"))
		std::cout << "true!\n";
	else
		std::cout << "False!\n";
	return 0;
}
