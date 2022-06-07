#include "leetCode.h"
#include "data.h"

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
            { // case of 1 1 0 or 1 0 1 or 0 1 1
                sum = 0;
                carry = 1;
            }
            else if (sum == 3)
            { // case  when a[i]=1,b[i]=1, carry=1;
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
        int _lengthOfStack = haystack.length();
        int _lengthOfNeedle = needle.length();
        if (_lengthOfStack == 0 && _lengthOfNeedle == 0)
            return 0;

        for (int index = 0; index < _lengthOfStack; index++)
        {
            string temp = haystack.substr(index, _lengthOfNeedle);
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
    vector<int> LeetCodeProblems::postorderTraversal(TreeNode *root)
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
    int LeetCodeProblems::removeDuplicates(vector<int> &nums)
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
    int LeetCodeProblems::searchInsert(vector<int> &nums, int target)
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

    int LeetCodeProblems::findPos(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size();
        int middle = (start + end) / 2;
        while (!(nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target) || (nums[middle] < target && target < nums[middle + 1])))
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
    int LeetCodeProblems::singleNumber(vector<int> &nums)
    {
        int res = {0};
        for (int i : nums)
        {
            res ^= i;
        }
        return res;
    }

    /**
     * @brief Solving the problems of deleteDuplicates
     *
     */
    ListNode *LeetCodeProblems::deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *currList = head;
        ListNode *nextList = nullptr;

        if (head->next != nullptr)
            nextList = head->next;

        while (nextList != nullptr)
        {
            if (currList->val != nextList->val)
            {
                currList = nextList;
                nextList = nextList->next;
            }
            else
            {
                currList->next = nextList->next;
                ListNode *temp = nextList;
                nextList = currList->next;

                delete temp;
                temp = nullptr;
            }
        }

        currList = nullptr;
        nextList = nullptr;

        return head;
    }

    /**
     * @brief Solving the problems of merge
     *
     */
    void LeetCodeProblems::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Don't you this way -> because you don't know the algorithm - even though this solution is very fast
        std::merge(nums2.rbegin() + (nums2.size() - n),
                   nums2.rend(),
                   nums1.rbegin() + (nums1.size() - m),
                   nums1.rend(), nums1.rbegin(),
                   [](const int l, const int r)
                   { return l >= r; });
    }

    int LeetCodeProblems::titleToNumber(string columnTitle)
    {
        int _size = columnTitle.length();
        int _res = 0;
        for (int i = 0; i < _size; i++)
        {
            if (i != 0)
            {

                _res = (_res * 26) + ((int)columnTitle[i] - 64);
            }
            else
            {
                _res += (int)columnTitle[i] - 64;
            }
        }
        return _res;
    }

    /**
     * @brief
     */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};