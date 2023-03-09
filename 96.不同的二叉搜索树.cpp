/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 21:32:40
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 21:32:45
 * @FilePath: /LeetCode/96.不同的二叉搜索树.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
 public:
  int numTrees(int n) {
    // dp[n] 长度为 n 的序列能构成不同二叉搜索树的个数
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
// @lc code=end
