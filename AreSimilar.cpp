//Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.
//
//Given two arrays a and b, check whether they are similar.
//
//Example
//
//For a = [1, 2, 3] and b = [1, 2, 3], the output should be
//areSimilar(a, b) = true.
//
//The arrays are equal, no need to swap any elements.
//
//For a = [1, 2, 3] and b = [2, 1, 3], the output should be
//areSimilar(a, b) = true.
//
//We can obtain b from a by swapping 2 and 1 in b.
//
//For a = [1, 2, 2] and b = [2, 1, 1], the output should be
//areSimilar(a, b) = false.
//
//Any swap of any two elements either in a or in b won't make a and b equal.

#include <iostream>
#include <vector>

bool areSimilar(std::vector<int> a, std::vector<int> b) {

    bool sim = false;

    // identify position with not similar elems
    std::vector<int> notSimPos;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            notSimPos.push_back(i);
    }
    // if two, compare swapwise
    if (notSimPos.size() == 0) {
        sim = true;
    }
    else if (notSimPos.size() == 2) {
        if (a[notSimPos[0]] == b[notSimPos[1]] && b[notSimPos[0]] == a[notSimPos[1]]) {
            sim = true;
        }
    }

    return sim;
	
}

int main()
{
	std::vector<int> a = { 4,6,2 };
	std::vector<int> b = { 4,6,3 };
	if (areSimilar(a, b) == true)
	{
		std::cout << "True!" << std::endl;
	}
	else
	{
		std::cout << "False!" << std::endl;
	}
	return 0;
}
