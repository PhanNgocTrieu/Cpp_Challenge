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


namespace leetcode {
    typedef enum {
        EASY    =   0,
        MEDI,
        HARD
    } levels;

    bool checkTarget(TreeNode *root, int target, int &result) {
        if (root == nullptr) {
            return false;
        }

        result += root->val;
        if (result == target && root->left == nullptr && root->right == nullptr) {
            return true;
        }

        if (checkTarget(root->left, target, result)) {
            return true;
        }
        else {
            result -= root->left ? root->left->val : 0;
        }
        
        if (checkTarget(root->right, target, result)) {
            return true;
        }
        else {
            result -= root->right ? root->left->val : 0;
        }
        return false;
        }

    bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    int result = 0;
    if (checkTarget(root, targetSum, result)) {
        return true;
    }

    return false;
    }
}

using namespace std;

#endif // COMMON_LEETCODE_H