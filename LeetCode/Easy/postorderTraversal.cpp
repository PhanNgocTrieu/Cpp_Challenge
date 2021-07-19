/*

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/





vector<int> postorderTraversal(TreeNode* root) {
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
