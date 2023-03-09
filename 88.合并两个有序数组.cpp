/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 19:22:14
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 19:22:20
 * @FilePath: /LeetCode/88.合并两个有序数组.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = nums1.size() - 1;
    int indexNums1 = m - 1;
    int indexNums2 = n - 1;

    while (k >= 0) {
      if (indexNums1 >= 0 && indexNums2 >= 0) {
        if (nums1[indexNums1] > nums2[indexNums2])
          nums1[k] = nums1[indexNums1--];
        else
          nums1[k] = nums2[indexNums2--];
      } else if (indexNums2 >= 0) {
        nums1[k] = nums2[indexNums2--];
      } else
        break;
      --k;
    }
  }
};
// @lc code=end
