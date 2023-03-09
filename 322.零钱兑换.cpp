/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 20:39:45
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 20:39:55
 * @FilePath: /LeetCode/322.零钱兑换.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int coinsSize = coins.size();
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto& coin : coins) {
        if (coin <= i) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};
// @lc code=end
