/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 21:47:32
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 22:54:29
 * @FilePath: /LeetCode/678.有效的括号字符串.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution {
 public:
  bool checkValidString(string s) {
    int maxLeft = 0;
    int minLeft = 0;
    for (auto& c : s) {
      if (c == '(') {
        ++maxLeft;
        ++minLeft;
      } else if (c == ')') {
        --maxLeft;
        --minLeft;
        minLeft = max(minLeft, 0);
      } else {
        ++maxLeft;
        --minLeft;
        minLeft = max(minLeft, 0);
      }
      if (maxLeft < 0) return false;
    }
    return minLeft == 0;
  }
};
// @lc code=end
