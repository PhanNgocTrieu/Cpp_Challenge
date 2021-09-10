//Comfortable Numbers
//Easy
//
//Let's say that number a feels comfortable with number b 
//if a ≠ b and b lies in the segment [a - s(a), a + s(a)], where s(x) is the sum of x's digits.
//
//How many pairs(a, b) are there, such that a < b, both aand b lie on the segment[l, r],
//and each number feels comfortable with the other(so a feels comfortable with band b feels comfortable with a)?
//
//	Example
//
//	For l = 10 and r = 12, the output should be
//	comfortableNumbers(l, r) = 2.
//
//	Here are all values of s(x) to consider :
//
//s(10) = 1, so 10 is comfortable with 9 and 11;
//s(11) = 2, so 11 is comfortable with 9, 10, 12 and 13;
//s(12) = 3, so 12 is comfortable with 9, 10, 11, 13, 14 and 15.
//Thus, there are 2 pairs of numbers comfortable with each other within the segment[10; 12]: (10, 11) and (11, 12).

#include <iostream>
#include <vector>
#include <algorithm>

void PrintPairs(std::vector<std::pair<int,int>> pairs)
{
    for (int i = 0; i < pairs.size(); i++)
    {
        std::cout << "i: " << i << " : " <<  pairs[i].first << " - " << pairs[i].second << std::endl;
    }
}

int comfortableNumbers(int l, int r) {
    std::cout << "Range(l,r): [" << l << ";" << r << "]: \n";
    if (l == r)
        return 0;
    int pairsNum = 0;
    std::vector<std::pair<int,int>> pairs;

    for (int i = l; i <= r; i++)
    {
        int S = 0;
        int temp = i;
        while (temp > 0) {
            S += temp%10;
            temp /= 10;
        }
        for (int j = i - S; j < i + S; j++)
        {
            if ( (j >= l) && (j <= r))
            {
                if ( j > i )
                {
                    pairs.push_back(std::make_pair(i,j));
                }

                if ( j < i)
                {
                    if (std::find(pairs.begin(),pairs.end(),std::make_pair(j,i)) != pairs.end())
                    {
                        pairsNum++;
                    }
                }
            }
        }
    }

    
    return pairsNum;
}


int main()
{
    std::cout << "\n" << comfortableNumbers(12,108);
    
	return 0;
}
