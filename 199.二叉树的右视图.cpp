/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    // 层序遍历
    queue<TreeNode*> myQueue;
    if (root == nullptr) return ans;
    myQueue.push(root);

    while (!myQueue.empty()) {
      int currentLayerSize = myQueue.size();
      for (int i = 0; i < currentLayerSize; ++i) {
        TreeNode* node = myQueue.front();
        myQueue.pop();
        if (i == 0) ans.push_back(node->val);
        if (node->right) myQueue.push(node->right);
        if (node->left) myQueue.push(node->left);
      }
    }

    return ans;
  }
};
// @lc code=end
