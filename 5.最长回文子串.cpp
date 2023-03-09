/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 20:28:33
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 20:42:50
 * @FilePath: /LeetCode/5.最长回文子串.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    /*
      动态规划解法：
      1. 建立dp，dp[i][j]表示s的子串[i, j]是否是回文串；
      2. 遍历dp，存储最大长度；
    */
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));

    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i; j < s.size(); ++j) {
        if (s[i] == s[j]) {
          if (j - i <= 1)
            dp[i][j] = true;
          else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
      }
    }
    int maxLength = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    for (int i = 0; i < dp.size(); ++i) {
      for (int j = i; j < dp[0].size(); ++j) {
        if (dp[i][j] && (j - i + 1 > maxLength)) {
          leftIndex = i;
          rightIndex = j;
          maxLength = rightIndex - leftIndex + 1;
        }
      }
    }
    return s.substr(leftIndex, maxLength);
  }
};
// @lc code=end
