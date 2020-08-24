#include <iostream>
#include <vector>
using namespace std;

bool IsCreasing(vector<int> sequence)
{
	int size = sequence.size() - 1;
	for (int i = 1; i <= size; i++)
	{
		if (sequence[i] <= sequence[i-1])
		{
			return false;
		}
	}
	return true;
}
vector<int> Removing(vector<int> sequence)
{
	int position = 0;
	vector<int> temp = sequence;
	int size = temp.size() - 1; // size = n - 1;
	for (int i = 1; i <= size; i++)
	{
		if (temp[i] <= temp[i-1])
		{
			position = temp[i - 1];
		}	
	}							
	for (int i = position; i < size; i++) // size < n - 2
	{
		temp[i] = temp[i + 1];
	}
	temp.pop_back();
	
	return temp;
}

bool IsStrictlyCreasing(vector<int> sequence)
{
	int size = sequence.size();
	int count = 0;
	if (IsCreasing(sequence) == true)
	{
		return true;
	}
	else
	{
		vector<int> temp = sequence;
		if (IsCreasing(Removing(temp)) == false)
		{
			return false;
		}
		return true;
	}
}

int main()
{
	vector<int> sequence1 = { 1,2,3,4,5,6,7};
	vector<int> sequence2 = { 10,2,3,4,5,6,7};
	vector<int> sequence3 = { 10,2,3,4,5,6,10};
	vector<int> sequence4 = { 1,1,2,2,3,3,4};
	vector<int> sequence5 = { 1,2,3,4,5,6,7,12};
	vector<int> sequence6 = { 1,3,5,7,9};
	vector<vector<int>> list_sequence = { sequence1, sequence2, sequence3, sequence4, sequence5, sequence6 };
	int size = list_sequence.size();
	for (int i = 0; i <= size - 1; i++)
	{
		if (IsCreasing(list_sequence[i]) == true)
		{
			cout << "vector: " << i << " is cresing! " << endl;
		}
		if (IsStrictlyCreasing(list_sequence[i]) == true)
		{
			cout << "vector: " << i << " is cresing by one removing! " << endl;
		}
	}
	cout << endl;

	return 0;
}
