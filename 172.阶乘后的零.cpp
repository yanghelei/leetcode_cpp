/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 18:55:42
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 18:55:53
 * @FilePath: /LeetCode/172.阶乘后的零.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
 public:
  int trailingZeroes(int n) {
    int ans = 0;
    for (int i = 5; i <= n; i += 5) {
      for (int x = i; x % 5 == 0; x /= 5) {
        ++ans;
      }
    }
    return ans;
  }
};

// @lc code=end
