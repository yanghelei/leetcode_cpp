/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 21:42:42
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 22:03:08
 * @FilePath: /LeetCode/1143.最长公共子序列.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // dp[i][j] 表示 text1[0 : i] 和 text2[0 : j] 上最长公共子序列的长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      char c1 = text1[i - 1];
      for (int j = 1; j <= n; j++) {
        char c2 = text2[j - 1];
        if (c1 == c2) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
