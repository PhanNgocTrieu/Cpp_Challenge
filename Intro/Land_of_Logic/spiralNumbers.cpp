#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralNumbers(int n)
{
	vector<vector<int>> res(n,vector<int> (n,0));
	int pos = 0;
	int len = n;
	int num = 1;
	
	while (pos <= n)
	{
		//std::cout << num << " ";
		for (int i = pos; i < len; i++)
		{
			res[pos][i] = num++;
		}

		//std::cout << "Running this 2: \n";
		for (int i = pos + 1; i < len; i++)
		{
			res[i][len - 1] = num++;
		}

		//std::cout << "Running this 3: \n";
		for	(int i = len - 2; i >= pos; i--) 
		{
			//cout << num << " ";
			res[len - 1][i] = num++;
		}

		//std::cout << "Running this 4: \n";
        for (int i = len - 2; i > pos; i--)
        {
            res[i][pos] = num++;
        }
		len--;
        pos++;
	}

    std::cout << "\nPrint!: \n"; //debug
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
    
	return res;
}

int main() {
	
	// your code goes here
	spiralNumbers(4);

	return 0;
}