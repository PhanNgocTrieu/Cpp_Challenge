//Given a sequence of integers as an array, determine whether it is possible to obtain a strictly increasing sequence by removing no more than one element from the array.
//Note: sequence a0, a1, ..., an is considered to be a strictly increasing if a0 < a1 < ... < an.
//Sequence containing only one element is also considered to be strictly increasing.

/*Example

For sequence = [1, 3, 2, 1], the output should be
almostIncreasingSequence(sequence) = false.

There is no one element in this array that can be removed in order to get a strictly increasing sequence.

For sequence = [1, 3, 2], the output should be
almostIncreasingSequence(sequence) = true.

You can remove 3 from the array to get the strictly increasing sequence[1, 2].Alternately, you can remove 2 to get the strictly increasing sequence[1, 3].

*/

#include <iostream>
#include <vector>
using namespace std;

bool IsCreasing(vector<int> sequence)
{
	int size = sequence.size();
	if (size == 1)
	{
		return true;
	}
	for (int i = 1; i < size; i++)
	{
		if (sequence[i] <= sequence[i - 1])
		{
			return false;
		}
	}
	return true;
}

vector<int> Removing(vector<int> sequence, int position)
{
	int size = sequence.size();
	vector<int> temp = sequence;
	if (position == size - 1)
	{
		temp.pop_back();
	}
	else
	{
		for (int i = position; i < size - 1; i++)
		{
			temp[i] = temp[i + 1];
		}
		temp.pop_back();
	}
	return temp;
}

bool IsStrictlyCreasing(vector<int> sequence)
{
	int count = 0;
	if (IsCreasing(sequence) == true)
	{
		return true;
	}
	int size = sequence.size();
	for (int i = 0; i < size; i++) // imax = n - 1;
	{
		vector<int> temp = sequence;
		if (IsCreasing(Removing(sequence,i)) == true)
		{
			count++;
		}
	}
	if (count != 0)
	{
		return true;
	}
	return false;
}

int main()
{
	vector<int> sequence1 = { 1,3,2,1 }; // false
	vector<int> sequence2 = { 1,3,2 };  // true
	vector<int> sequence3 = { 10,2,3,4,5,6,10 }; // true
	vector<int> sequence4 = { 1,1,2,2,3,3,4 }; // false
	vector<int> sequence5 = { 1,2,1,2 }; // false
	vector<int> sequence6 = { 1,3,5,7,9 }; // true
	vector<int> sequence7 = { 3,5,67,98,3 }; // true

	
	vector<vector<int>> list_sequence = { sequence1, sequence2, sequence3, sequence4, sequence5, sequence6, sequence7 };
	int size = list_sequence.size();


	for (int i = 0; i < size; i++)
	{

		cout << "vector " << i << ": ";
		for (int j = 0; j < list_sequence[i].size(); j++)
		{
			cout << list_sequence[i][j] << " ";
		}
		cout << endl;
		cout << endl;
	}

	for (int i = 0; i <= size - 1; i++)
	{
		if (IsStrictlyCreasing(list_sequence[i]) == true)
		{
			cout << "vector: " << i << " is true " << endl;
		}
	}
	cout << endl;

	return 0;
}
