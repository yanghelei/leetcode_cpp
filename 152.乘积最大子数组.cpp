/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 16:53:18
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 16:53:24
 * @FilePath: /LeetCode/152.乘积最大子数组.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    vector<int> maxF(nums);  // 以第 i 个元素结尾的 乘积最大 子数组的乘积
    vector<int> minF(nums);  // 以第 i 个元素结尾的 乘积最小 子数组的乘积
    for (int i = 1; i < nums.size(); ++i) {
      maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
      minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
  }
};
// @lc code=end
