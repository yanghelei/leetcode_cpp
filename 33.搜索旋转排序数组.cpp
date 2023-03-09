/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 01:11:36
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 02:30:29
 * @FilePath: /LeetCode/33.搜索旋转排序数组.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size() - 1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) return mid;
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[n]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};
// @lc code=end
