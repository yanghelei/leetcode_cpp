/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 16:54:21
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 17:11:54
 * @FilePath: /LeetCode/31.下一个排列.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[i] >= nums[j]) j--;
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
// @lc code=end
