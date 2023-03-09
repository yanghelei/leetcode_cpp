/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 13:00:25
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 13:00:31
 * @FilePath: /LeetCode/122.买卖股票的最佳时机-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int last = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      ans += max(prices[i] - last, 0);
      last = prices[i];
    }
    return ans;
  }
};
// @lc code=end
