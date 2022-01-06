#include "leetCode.h"

namespace leetcode
{
    /**
     * **********************************************************************************
     *                       @brief Problems of Easy Levels                             *
     * **********************************************************************************
     */

    /**
     * @brief Solving the problems of addBinary
     * 
     */
    string LeetCodeProblems::addBinary(string a, string b)
    {
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        string res = "";

        while ((m >= 0 || n >= 0) || carry)
        {
            int d1 = (m >= 0) ? a[m--] - '0' : 0;
            int d2 = (n >= 0) ? b[n--] - '0' : 0;
            int sum = d1 + d2 + carry;

            if (sum == 2)
            { //case of 1 1 0 or 1 0 1 or 0 1 1
                sum = 0;
                carry = 1;
            }
            else if (sum == 3)
            { //case  when a[i]=1,b[i]=1, carry=1;
                sum = 1;
                carry = 1;
            }
            else
                carry = 0;
            res.insert(0, to_string(sum));
        }

        return res;
    }



    /**
     * @brief Solving the problems of longestCommonPrefix
     * 
     * Algorithm:
     * 
     * from above example we can see:
     * taking the first element is standard:
     * strs[0] ------ f ------- l ------- o 
     * checking: 
     * strs[1] ------ ^ ------- ^ ------- ^
     * strs[2] ------ ^ ------- ^ ------- x -> resturn res
     * --------------------------------------
     * res =          f        fl        return
     * 
     * 
     */
    string LeetCodeProblems::longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        string res = "";
        int size = strs.size();
        int len = strs[0].length();

        for (int i = 0; i < len; i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < size; j++)
            {
                if (strs[j][i] != c)
                {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }

    /**
     * @brief Solving the problems of twoSum
     * 
     */
    vector<int> LeetCodeProblems::twoSum(vector<int> &nums, int target)
    {
        vector<int> res;

        int len = nums.size();

        for (int index = 0; index < len; index++)
        {
            // target = num_1 + num_2 => num_2 = target - num_1
            int num_2 = target - nums[index];
            int start = index + 1;
            while (start < len)
            {
                if (nums[start] == num_2)
                {
                    res.push_back(index);
                    res.push_back(start);
                    return res;
                }
                start++;
            }
        }
        return res;
    }

    int LeetCodeProblems::strStr(string haystack, string needle) 
    {
        if (haystack.length() == 0 && needle.length() == 0)
            return 0;

        int needle_length = needle.length();

        for (int index = 0; index < haystack.length(); index++)
        {
            string temp = haystack.substr(index, needle_length);
            if (temp == needle)
                return index;
        }

        return -1;
    }

    /**
     * @brief Solving the problems of postorderTraversel
     * 
     *  
     */
    vector<int> LeetCodeProblems::postorderTraversal(TreeNode* root) 
    {
        vector<int> res{};
        if (root == NULL)
            return res;
        else
        {
            vector<int> temp = postorderTraversal(root->left);
            std::copy(temp.begin(), temp.end(), std::back_inserter(res));
        
            temp = postorderTraversal(root->right);
            std::copy(temp.begin(), temp.end(), std::back_inserter(res));
        
            res.push_back(root->val);
        }
        return res;
    }

    /**
     * @brief Solving the problems of removeDuplicates
     * 
     * @param nums 
     * @return int 
     */
    int LeetCodeProblems::removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return 1;
        vector<int>::iterator ip;
        ip = std::unique(nums.begin(), nums.end());
        // Resizing the vector so as to remove the undefined terms
        nums.resize(std::distance(nums.begin(), ip));

        return nums.size();
    }

    /**
     * @brief Solving the problems of searchInsert
     * 
     * @param nums 
     * @param target 
     * @return int 
     */
    int LeetCodeProblems::searchInsert(vector<int>& nums, int target) 
    {
        if (target <= nums[0])
            return 0;
        int len = nums.size();
        if (target > nums[len - 1])
            return len;
        if (target == nums[len - 1])
        {
            return len - 1;
        }
        return findPos(nums, target);   
    }

    int LeetCodeProblems::findPos(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size();
        int middle = (start + end) / 2;
        while (!(nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target) || (nums[middle] < target && target < nums[middle + 1]) ))
        {
            middle = (start + end) / 2;

            if (nums[middle] < target)
                start = middle;
            if (nums[middle] > target)
                end = middle;
        }

        if (nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target))
            return middle;
        if (nums[middle] < target && target < nums[middle + 1])
            return middle + 1;
        
        return middle;
    }




    /**
     * @brief Solving the problems of singleNumber
     *  
     */
    int LeetCodeProblems::singleNumber(vector<int>& nums) 
    {   
        int res = {0};
        for (int i : nums)
        {
        res ^= i;
        }
        return res;
    }






    /**
     * **********************************************************************************
     *                       @brief Problems of Medium Levels                           *
     * **********************************************************************************
     */


    /**
     * @brief Solving the problems of isValid
     * 
     */
    bool LeetCodeProblems::isValid(string s) 
    {
        if (s.length() == 1)
            return false;
        if (s[0] == '}' || s[0] == ']' || s[0] == ')')
            return false;

        stack<char> check;
        map<char, char> brackets{
            {')','('},
            {'}','{'},
            {']','['}
        };
        
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                check.push(c);
            else
            {
                if (check.empty())
                    return false;
                if (check.top() == brackets[c])
                    check.pop();
                else
                    return false;
            }
        }
        return check.size() == 0 ? true : false;
    }


    /**
     * @brief Solving the problems of combinationSum
     */
    vector<vector<int>> LeetCodeProblems::combinationSum(vector<int>& candidates, int target) 
    {
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



    /**
     * @brief Solving the problems of intToRoman
     */
    string LeetCodeProblems::intToRoman(int num) {
        map<int, string> romanList
        {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
            string res = "";
            int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            int i = 0;
            while(num > 0)
            {
                if (num < arr[i])
                {
                    i++;
                    continue;
                }
                else
                {
                    int temp = num / arr[i];
                    // adding numbers of words
                    for (int j = 0; j < temp; j++)
                    {
                        res += romanList[arr[i]];
                    }
                    num = num % arr[i];
                    i++;
                }
            }
            
            
        return res; 
    }

    /**
     * @brief Solving the problems of myAtoi
     */
    int LeetCodeProblems::myAtoi(string s)
    {
        const int n = s.length();
        // 1.passing leading space
        int start = 0;
        while (start < n && s[start] == ' ') {
            start++;
        }
        if (start == n) return 0;
        // 2. sign
        bool positive = true;
        if (s[start] == '-' || s[start] == '+') {
            positive = s[start] == '+';
            start++;
        }
        // 3. convert string to number
        if (!isdigit(s[start])) return 0;
        int ans = 0;
        int max_unit = INT_MAX % 10;
        int min_unit = INT_MIN % 10;
        while (start < n && isdigit(s[start])) {
            int unit = (s[start++] - '0');
            if (!positive) {
                unit = -unit;
            }
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && unit > max_unit)) return INT_MAX;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && unit < min_unit)) return INT_MIN;
            ans = ans * 10 + unit;
        }

        return ans;

        /*  //  Second way
        {
            int i = 0;
            while(s[i] == ' ') ++i;
            int sig = 1;
            if(s[i] == '-')
            {
                sig = -1;
                ++i;
            }
            else if(s[i] == '+')
            {
                ++i;
            }
            if(s[i] < '0' || s[i] > '9') return 0;
            ll ans = 0;
            while(s[i] >= '0' && s[i] <= '9' && i < s.size())
            {
                ans *= 10;
                ans += (s[i++] - '0');
                if(ans*sig >= INT_MAX) return INT_MAX;
                if(ans*sig <= INT_MIN) return INT_MIN;
            }
            return (int) ans*sig;
        }
        */
    }


    /**
     * @brief Solving the problems of longestPalindrome
     * 
     */
    string LeetCodeProblems::longestPalindrome(string s) 
    {
        string ans = "";
        int len = 0, maxLen = 0, idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            int left = i-1, right = i+1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);
            
            left = i; right = i+1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);
        }
        
        if (maxLen)
            ans = s.substr(idx, maxLen);
        return ans;
    }
    
    int LeetCodeProblems::pallindromeLength(int &l, int &r, string &s) 
    {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }
        l++; r--;
        return (r-l+1);
    }

    

};