/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 01:07:44
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-10 13:02:26
 * @FilePath: /LeetCode/各类排序算法/快速排序.cpp
 * @Description:
 */
class Solution {
  void quickSort(vector<int>& nums, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;

    int firstNum = nums[startIndex];

    int l = startIndex;
    int r = endIndex;
    while (l < r) {
      // 从后往前走，将比第一个小的移到前面
      while (l < r && nums[r] >= firstNum) --r;
      if (l < r) {
        nums[l] = nums[r];
      }
      // 从前往后走，将比第一个大的移到后面
      while (l < r && nums[l] <= firstNum) ++l;
      if (l < r) {
        nums[r] = nums[l];
      }
    }
    nums[l] = firstNum;
    // 自顶向下
    quickSort(nums, startIndex, l - 1);
    quickSort(nums, l + 1, endIndex);
  }

 public:
  vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    quickSort(nums, 0, n - 1);
    return nums;
  }
};