/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:51:13
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 01:34:47
 * @FilePath: /LeetCode/215.数组中的第k个最大元素.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
// 这里使用快速排序进行处理，时间复杂度O(nlogn)，不满足题目要求
class Solution {
 public:
  void quickSort(vector<int>& nums, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;

    int pivot = nums[startIndex];

    int l = startIndex;
    int r = endIndex;

    while (l < r) {
      while (l < r && nums[r] >= pivot) --r;
      if (l < r) nums[l] = nums[r];
      while (l < r && nums[l] <= pivot) ++l;
      if (l < r) nums[r] = nums[l];
    }
    nums[l] = pivot;
    quickSort(nums, startIndex, l - 1);
    quickSort(nums, l + 1, endIndex);
  }

  int findKthLargest(vector<int>& nums, int k) {
    quickSort(nums, 0, nums.size() - 1);
    return nums[nums.size() - k];
  }
};
// @lc code=end
