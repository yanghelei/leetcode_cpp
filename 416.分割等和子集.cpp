/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 15:54:03
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 15:54:08
 * @FilePath: /LeetCode/416.分割等和子集.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return false;

    // 如果 sum 是奇数，无法被分为两个子集
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum / 2;

    // 获取 nums 中最大的数
    int maxNum = *max_element(nums.begin(), nums.end());
    // 最大的数大于 target，无法被分为两个子集
    if (maxNum > target) return false;

    // dp[i][j] 表示从数组的 [0, i] 下标范围内选取若干个正整数(可以是 0 个)
    // 是否存在一种选取方案使得被选取的正整数的和等于 j
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;

    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
      int num = nums[i];
      for (int j = 1; j <= target; j++) {
        if (j >= num) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][target];
  }
};
// @lc code=end
