/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 19:32:32
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 19:32:38
 * @FilePath: /LeetCode/53.最大子数组和.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    // dp[i] 表示：以 nums[i] 结尾的连续子数组的最大和
    vector<int> dp(len);
    dp[0] = nums[0];

    int ans = dp[0];
    for (int i = 1; i < len; i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      ans = max(dp[i], ans);
    }
    return ans;
  }
};
// @lc code=end
