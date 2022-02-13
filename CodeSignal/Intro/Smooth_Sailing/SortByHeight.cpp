//Some people are standing in a row in a park.There are trees between them which cannot be moved.Your task is to rearrange the people by their heights in a non - descending order without moving the trees.People can be very tall!
//
//Example
//
//For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
//sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].
//
//Input / Output
//
//[execution time limit] 0.5 seconds(cpp)
//
//[input] array.integer a
//
//If a[i] = -1, then the ith position is occupied by a tree.Otherwise a[i] is the height of a person standing in the ith position.
//
//Guaranteed constraints :
//1 ≤ a.length ≤ 1000,
//-1 ≤ a[i] ≤ 1000.
//
//[output] array.integer
//
//Sorted array a with all the trees untouched.

#include <iostream>
#include <vector>


std::vector<int> sortByHeight(std::vector<int> &a) {
	
	int size = a.size();
	std::vector<int> temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] != -1 && a[j] != -1)
			{
				if (a[i] > a[j])
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	//temp = a;
	//return temp;
	return a;
}

int main()
{
	std::vector<int> a = {-1, 150, 190, 170, -1, -1, 160, 180};
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	sortByHeight(a);
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
