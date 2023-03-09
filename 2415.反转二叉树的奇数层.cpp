/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:28:34
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 00:31:29
 * @FilePath: /LeetCode/2415.反转二叉树的奇数层.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
  TreeNode* reverseOddLevels(TreeNode* root) {
    int layer = 0;
    int count = 0;

    queue<TreeNode*> myQueue;
    if (root != nullptr) myQueue.push(root);

    stack<int> tempVals;
    queue<TreeNode*> tempNodes;

    // 层序遍历 BFS
    while (!myQueue.empty()) {
      int size = myQueue.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* node = myQueue.front();
        if (layer % 2 != 0) {
          tempNodes.push(node);
          tempVals.push(node->val);
        }
        if (node->left != nullptr) myQueue.push(node->left);
        if (node->right != nullptr) myQueue.push(node->right);
        myQueue.pop();
      }
      if (layer % 2 != 0) {
        while (!tempVals.empty()) {
          tempNodes.front()->val = tempVals.top();
          tempNodes.pop();
          tempVals.pop();
        }
      }
      ++layer;
    }

    return root;
  }
};
// @lc code=end
