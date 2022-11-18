#ifndef COMMON_LEETCODE_H
#define COMMON_LEETCODE_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <sstream>
#include <queue>
#include "data.h"

namespace leetcode
{
    typedef enum
    {
        EASY = 0,
        MEDI,
        HARD
    } levels;


    /**
     * @brief Function support for easy-"hasPathSum" problem!
     *
     */
    bool checkTarget(TreeNode *root, int target, int &result)
    {
        if (root == nullptr)
        {
            return false;
        }
        result += root->val;
        std::cout << "Cur node: " << root->val << " - result: " << result << std::endl;
        if (result == target && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }

        std::cout << "Calling left! -> ";
        if (checkTarget(root->left, target, result))
        {
            return true;
        }
        else
        {
            result -= root->left ? root->left->val : 0;
        }
        std::cout << std::endl;
        std::cout << "Calling right! -> ";
        if (checkTarget(root->right, target, result))
        {
            return true;
        }
        else
        {
            result -= root->right ? root->right->val : 0;
        }
        std::cout << std::endl;
        return false;
    }
}

using namespace std;

#endif // COMMON_LEETCODE_H