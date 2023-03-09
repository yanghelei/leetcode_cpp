/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 19:31:44
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 19:31:48
 * @FilePath: /LeetCode/121.买卖股票的最佳时机.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int buyIn = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
      if (prices[i] < buyIn) {
        buyIn = prices[i];
      } else {
        ans = max(ans, prices[i] - buyIn);
      }
    }
    return ans;
  }
};
// @lc code=end
