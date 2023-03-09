/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:57:06
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 00:59:05
 * @FilePath: /LeetCode/22.括号生成.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    func(res, "", 0, 0, n);
    return res;
  }

  void func(vector<string> &res, string str, int l, int r, int n) {
    // l 是左括号的个数， r 是右括号的个数， n 是总共的括号数
    if (l > n || r > n || r > l) return;
    if (l == n && r == n) {
      res.push_back(str);
      return;
    }
    func(res, str + '(', l + 1, r, n);
    func(res, str + ')', l, r + 1, n);
    return;
  }
};
// @lc code=end
