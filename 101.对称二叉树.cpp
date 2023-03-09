/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 21:34:38
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 21:35:20
 * @FilePath: /LeetCode/101.对称二叉树.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
 private:
  bool myCompare(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b != nullptr)
      return false;
    else if (a != nullptr && b == nullptr)
      return false;
    else if (a == nullptr && b == nullptr)
      return true;
    else if (a->val != b->val)
      return false;
    else {
      bool c1 = myCompare(a->left, b->right);
      bool c2 = myCompare(a->right, b->left);
      return c1 && c2;
    }
  }

 public:
  bool isSymmetric(TreeNode* root) {
    bool result = myCompare(root->left, root->right);
    return result;
  }
};
// @lc code=end
