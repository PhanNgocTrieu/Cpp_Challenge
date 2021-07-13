/*Let's call two integers A and B friends
 *if each integer from the array divisors is either a divisor of both A and B or neither A nor B.
 *If two integers are friends, they are said to be in the same clan.
 *How many clans are the integers from 1 to k, inclusive, broken into?

Example

For divisors = [2, 3] and k = 6, the output should be
numberOfClans(divisors, k) = 4.

The numbers 1 and 5 are friends and form a clan,
2 and 4 are friends and form a clan,
and 3 and 6 do not have friendsand each is a clan by itself.
So the numbers 1 through 6 are broken into 4 clans.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int numberOfClans(vector<int> divisors, int k) {
    set<string> div_set;
    int len = divisors.size();
    
    for (int i = 1; i <= k; i++)
    {
        string num_div = "1";

        for (int j = 0; j < len; j++)
        {
            if (i % divisors[j] == 0)
                num_div += to_string(divisors[j]);
        }
        std::cout << num_div << "\n";
        div_set.insert(num_div);
    }


    return div_set.size();
}

int main()
{
    vector<int> divisors{ 6, 2, 2, 8, 9, 2, 2, 2, 2 };
    std::cout << numberOfClans(divisors, 10);
	return 0;
}