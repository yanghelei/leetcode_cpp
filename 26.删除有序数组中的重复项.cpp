/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 14:45:02
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 14:45:11
 * @FilePath: /LeetCode/26.删除有序数组中的重复项.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int slowIndex = 1, fastIndex = 1;  // 双指针
    while (fastIndex < nums.size()) {
      // fastIndex 指向的为已经出现过的元素
      if (nums[fastIndex] == nums[fastIndex - 1]) {
        ++fastIndex;
      }
      // fastIndex 指向的是新元素
      else {
        nums[slowIndex++] = nums[fastIndex];
        ++fastIndex;
      }
    }
    return slowIndex;
  }
};
// @lc code=end
