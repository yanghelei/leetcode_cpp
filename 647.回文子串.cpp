/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 19:01:13
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 19:14:03
 * @FilePath: /LeetCode/647.回文子串.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
 public:
  int countSubstrings(string s) {
    /* 定义存储结果的变量 */
    int result = 0;

    /* 定义dp数组 dp[i][j] 表示 【i，j】区间中的字符串是不是回文子串 */
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));

    for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
      for (int j = i; j < s.size(); j++) {
        if (s[i] == s[j]) {
          // j - i < 1 说明在区间内 只有一个字符 所以是回文子串
          // j - i == 1 说明在区间内 有两个相等的字符 所以是回文子串
          if (j - i <= 1) {
            result++;
            dp[i][j] = true;
          } else if (dp[i + 1][j - 1]) {
            result++;
            dp[i][j] = true;
          }
        }
      }
    }
    return result;
  }
};
// @lc code=end
