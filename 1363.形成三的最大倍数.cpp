/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:23:05
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 00:28:04
 * @FilePath: /LeetCode/1363.形成三的最大倍数.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1363 lang=cpp
 *
 * [1363] 形成三的最大倍数
 */

// @lc code=start
class Solution {
 public:
  string largestMultipleOfThree(vector<int>& digits) {
    vector<int> cnt(10);    // 每个数字出现的次数
    vector<int> modulo(3);  // 每个数字 模3 出现的次数
    int sum = 0;
    // 计算各个数出现的次数，余数的次数，digits之和
    for (int digit : digits) {
      ++cnt[digit];
      ++modulo[digit % 3];
      sum += digit;
    }

    int rest = 0;        // 删除的数的个数
    int remove_mod = 0;  // 要删除的元素模余几
    // 如果 sum 模3余1，需要删除 1个余1 的元素 或者 2个余2 的元素
    if (sum % 3 == 1) {
      if (modulo[1] >= 1) {
        remove_mod = 1;
        rest = 1;
      } else {
        remove_mod = 2;
        rest = 2;
      }
    }
    // 如果 sum 模3余2，需要删除 2个余1 的元素 或者 1个余2 的元素
    else if (sum % 3 == 2) {
      if (modulo[2] >= 1) {
        remove_mod = 2;
        rest = 1;
      } else {
        remove_mod = 1;
        rest = 2;
      }
    }
    string ans;
    for (int i = 0; i <= 9; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        if (rest && remove_mod == i % 3) {
          --rest;
        } else {
          ans += static_cast<char>(i + 48);
        }
      }
    }
    if (ans.size() && ans.back() == '0') ans = "0";
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
