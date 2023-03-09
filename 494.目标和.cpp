/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 19:00:18
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 19:00:26
 * @FilePath: /LeetCode/494.目标和.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
 private:
  int result;
  void backTracking(vector<int>& nums, int target, int startIndex, int sum) {
    if (startIndex == nums.size()) {
      if (sum == target) ++result;
      return;
    } else {
      backTracking(nums, target, startIndex + 1, sum + nums[startIndex]);
      backTracking(nums, target, startIndex + 1, sum - nums[startIndex]);
    }
  }

 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    this->result = 0;
    backTracking(nums, target, 0, 0);
    return this->result;
  }
};
// @lc code=end
