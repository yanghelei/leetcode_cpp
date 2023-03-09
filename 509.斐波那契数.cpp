/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 22:10:25
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 22:12:26
 * @FilePath: /LeetCode/509.斐波那契数.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    if (n < 2) return n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
// @lc code=end
