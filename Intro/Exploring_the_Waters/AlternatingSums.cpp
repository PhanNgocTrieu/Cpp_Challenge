//Several people are standing in a rowand need to be divided into two teams.The first person goes into team 1, the second goes into team 2, the third goes into team 1 again, the fourth into team 2, and so on.
//
//You are given an array of positive integers - the weights of the people.Return an array of two integers, where the first element is the total weight of team 1, and the second element is the total weight of team 2 after the division is complete.
//
//Example
//
//For a = [50, 60, 60, 45, 70], the output should be
//alternatingSums(a) = [180, 105].

#include <iostream>
#include <vector>

std::vector<int> alternatingSums(std::vector<int> a) {
	int size = a.size();
	int Team1_point = 0;
	int Team2_point = 0;
	std::vector<int> output;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			Team1_point += a[i];
		}
		else
		{
			Team2_point += a[i];
		}
	}
	output.push_back(Team1_point);
	output.push_back(Team2_point);

	return output;
}


int main()
{	
	std::vector<int> a = { 50, 60, 60, 45, 70 };
	alternatingSums(a);
	return 0;
}
