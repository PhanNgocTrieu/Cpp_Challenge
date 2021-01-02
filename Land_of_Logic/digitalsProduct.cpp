/*
Given an integer product, find the smallest positive (i.e. greater than 0) integer the product of whose digits is equal to product. 
If there is no such integer, return -1 instead.

Example

For product = 12, the output should be
digitsProduct(product) = 26;
For product = 19, the output should be
digitsProduct(product) = -1.
*/

#include <iostream>
#include <vector> 

void Find(std::vector<int> &track, int &product)
{
    std::cout << "running this! \n";

    for (int i = 9; i > 1; i--)
    {
        while (product % i == 0)
        {
            track.push_back(i);
            std::cout << "i" << i << "\n";
            product = product / i;
            std::cout << "product " << product << '\n'; 
        }
    }
}

int digitsProduct(int product) {   
    std::vector<int> track;
    int res = 0;
    if (product == 0)
    {
        return 10;
    }

    if (product > 0 && product < 10)
    {
        return product;
    }
        
    Find(track,product);
    std::cout << "Size of track: " << track.size() << "\n";
    if (track.size() == 0)
    {
        return -1;
    }
    else
    {
        for (int i = track.size() - 1; i >= 0; i--)
            {
            std::cout << "Track: " << track[i] << "\n";
            res = res + track[i];
            res = res*10;
            }
        res = res / 10;

        if (product != 1)
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
        
}


int main()
{
   // std::cout << digitalNumber(2312) << "\n";
    std::cout << digitsProduct(484) << "\n";
    return 0;
}
