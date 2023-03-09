/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 21:36:19
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 21:40:15
 * @FilePath: /LeetCode/剑指 Offer 42. 连续子数组的最大和.cpp
 * @Description:
 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size() + 1);
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      ans = max(dp[i], ans);
    }
    return ans;
  }
};