/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]
*/

// using stack - we can use queue (but we have to implement it!)
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;

    for (int i=0 ; i < candidates.size(); i++) {
        vector<Combination> stack;
        struct Combination com;

        // check single value
        if(candidates[i] == target)
        {
            vector<int> okay;
            okay.push_back(candidates[i]);
            res.push_back(okay);
            continue;
        }

        //push i vao stack
        com.arr.push_back(candidates[i]);
        com.sum += candidates[i];
        com.idx = i;
        stack.push_back(com);

        // duyet stack
        while(stack.size()!=0)
        {
            // lay ra phan tu cuoi cung
            struct Combination temp;
            temp = stack[stack.size()-1]; 
            stack.pop_back();

            for (int j = temp.idx; j < candidates.size(); j++)
            {
                struct Combination temp2;
                temp2 = temp;
                if(temp.sum + candidates[j] <= target)
                {
                    temp2.arr.push_back(candidates[j]);
                    temp2.sum += candidates[j];
                    temp2.idx = j;
                    stack.push_back(temp2);
                    if(temp.sum + candidates[j] == target)
                    {
                        res.push_back(temp2.arr);
                        stack.pop_back();
                    }

                }
            }
        }
    }
    return res;
}
