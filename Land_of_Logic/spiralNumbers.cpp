// Construct a square matrix with a size N × N containing integers from 1 to N * N in a spiral order,
// starting from top-left and in clockwise direction.
// Example:
// For n = 3, the output should be
// spiralNumbers(n) = [[1, 2, 3],
//                     [8, 9, 4],
//                     [7, 6, 5]]


//----------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralNumbers(int n)
{
	vector<vector<int>> res;
	int pos = 0;
	int num = 1;
	
	while (num <= n*n)
	{
		
		for (int i = pos; i < n; i++)
		{
			res[pos][i] = num++; //coud not run to end of this loop
		}

		for (int i = pos + 1; i < n; i++)
		{
			res[i][n - 1] = num++;
		}

        for	(int i = n - 2; i >= pos; i--) 
        {
            res[n - 1][i] = num++;
        }

        for (int i = n - 2; i > pos; i--)
        {
            res[i][pos] = num++;
        }
		n--;
        pos++;
	}

    cout << "Coming to this!\n"; //debug
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    
	return res;
}

int main() {
	
	// your code goes here
	spiralNumbers(4);

	return 0;
}
