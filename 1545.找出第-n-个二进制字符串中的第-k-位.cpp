/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 17:42:52
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 17:43:09
 * @FilePath: /LeetCode/1545.找出第-n-个二进制字符串中的第-k-位.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1545 lang=cpp
 *
 * [1545] 找出第 N 个二进制字符串中的第 K 位
 */

// @lc code=start
class Solution {
 public:
  char invert(char s) { return (s == '0') ? '1' : '0'; }

  char findKthBit(int n, int k) {
    // 第 n 个字符串的长度：2^n - 1
    int len = (1 << n) - 1;

    if (n == 1) return '0';

    int mid = len / 2;

    if (mid == k - 1)
      return '1';  // mid 一定为 1
    else {
      if (mid < k - 1)
        return invert(findKthBit(n - 1, len - (k - 1)));
      else
        return findKthBit(n - 1, k);
    }
    return '0';
  }
};

// @lc code=end
