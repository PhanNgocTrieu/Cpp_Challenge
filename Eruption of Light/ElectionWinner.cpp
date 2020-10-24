//Elections are in progress!
//
//Given an array of the numbers of votes given to each of the candidates so far, 
//and an integer k equal to the number of voters who haven't cast their vote yet,
//find the number of candidates who still have a chance to win the election.
//
//The winner of the election must secure strictly more votes than any other candidate.
//If two or more candidates receive the same(maximum) number of votes, assume there is no winner at all.
//
//Example
//
//For votes = [2, 3, 5, 2] and k = 3, the output should be
//electionsWinners(votes, k) = 2.
//
//The first candidate got 2 votes.Even if all of the remaining 3 candidates vote for him, 
//he will still have only 5 votes, i.e.the same number as the third candidate, so there will be no winner.
//The second candidate can win if all the remaining candidates vote for him(3 + 3 = 6 > 5).
//The third candidate can win even if none of the remaining candidates vote for him.For example, 
//if each of the remaining voters cast their votes for each of his opponents, 
//he will still be the winner(the votes array will thus be[3, 4, 5, 3]).
//The last candidate can't win no matter what (for the same reason as the first candidate).
//Thus, only 2 candidates can win(the second and the third), which is the answer.

#include <iostream>
#include <vector>
#include <algorithm>


int electionsWinners(std::vector<int> votes, int k) {

	int size = votes.size();
	int winners = 1;
	int max = *max_element(votes.begin(), votes.end());	

	//---------------finding the position of max -------------
	auto it = std::find(votes.begin(),
		votes.end(), max);
	// If element was found 
	int index = std::distance(votes.begin(),it);
	std::cout << index << std::endl;


	//---------------- Finding Winners --------------------
	if (k == 0)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			// if no candidates more and we have 2 or more the same votes -> no one would be winner
			// return 0;
			if (votes[i] == max)
			{
				count++;
			}
			if (count == 2)
			{
				return 0;
			}
		}

		// if no one equal to element of max -> just himself be winners
		return 1;
	}


	// -------------- k != 0 ------------------- 
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			continue;
		}
		else
		{
			int temp = votes[i] + k;
			if (temp > max)
			{
				winners++;
			}
		}
	}
	return winners;
}


int main()
{
	std::vector<int> votes = { 1, 3, 3, 1, 1 };
	int k = 0;
	std::cout << electionsWinners(votes, k);
	return 0;
}
