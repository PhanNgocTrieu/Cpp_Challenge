//Call two arms equally strong if the heaviest weights they each are able to lift are equal.
//
//Call two people equally strong if their strongest arms are equally strong(the strongest arm can be both the right and the left), and so are their weakest arms.
//
//Given yourand your friend's arms' lifting capabilities find out if you two are equally strong.
//
//Example
//
//For yourLeft = 10, yourRight = 15, friendsLeft = 15, and friendsRight = 10, the output should be
//areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true;
//For yourLeft = 15, yourRight = 10, friendsLeft = 15, and friendsRight = 10, the output should be
//areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true;
//For yourLeft = 15, yourRight = 10, friendsLeft = 15, and friendsRight = 9, the output should be
//areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = false.

#include <iostream>

bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {
	int my_weakest = yourLeft < yourRight ? yourLeft : yourRight;
	int my_strongest = yourLeft > yourRight ?  yourLeft : yourRight;
	int myfriend_weakest = friendsLeft < friendsRight ? friendsLeft : friendsRight;
	int myfriend_strongest = friendsLeft > friendsRight ? friendsLeft : friendsRight;
	std::cout << "My Strongest Arm: " << my_strongest << std::endl;
	std::cout << "My weakest Arm: " << my_weakest << std::endl;
	std::cout << "My friend's Strongest Arm: " << myfriend_strongest << std::endl;
	std::cout << "My friend's weakest Arm: " << myfriend_weakest << std::endl;

	if (my_strongest == myfriend_strongest && my_weakest == myfriend_weakest)
	{
		return	true;
	}
	return false;
}

int main()
{
	
	if (areEquallyStrong(10, 15, 15, 10) == true)
	{
		std::cout << "Equal!" << std::endl;
	}
	return 0;
}
