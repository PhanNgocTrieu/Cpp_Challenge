// Given an integer N, find its factorial.

// Example 1:

// Input: N = 5
// Output: 120
// Explanation : 5! = 1*2*3*4*5 = 120
// Example 2:

// Input: N = 10
// Output: 3628800
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800


class Solution {
public:

    int multiply(int x, vector<int>& res)
    {
        int carry = 0;  // Initialize carry
        int res_size = res.size();
        // One by one multiply n with individual digits of res[]
        for (int i=0; i<res_size; i++)
        {
            int prod = res[i] * x + carry;
     
            // Store last digit of 'prod' in res[] 
            res[i] = prod % 10; 
     
            // Put rest in carry
            carry  = prod/10;   
        }
     
        // Put carry in res and increase result size
        while (carry)
        {
            res.push_back(carry%10);
            carry = carry/10;
            res_size++;
        }
        return res_size;
    }
    vector<int> factorial(int N){
       vector<int> res = {1};
        int res_size = 1;
     
        // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
        for (int x=2; x<=N; x++)
            res_size = multiply(x, res);
        
        
        reverse(res.begin(),res.end());
        return res;
    }
};