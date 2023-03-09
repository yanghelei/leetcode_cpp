/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 01:35:43
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 02:04:24
 * @FilePath: /LeetCode/3.无重复字符的最长子串.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    unordered_set<char> mySet;
    int slowIndex = 0;
    int fastIndex = 0;
    while (fastIndex < s.size()) {
      if (mySet.find(s[fastIndex]) == mySet.end()) {
        mySet.insert(s[fastIndex]);
        maxLength = max(maxLength, fastIndex - slowIndex + 1);
      } else {
        while (s[slowIndex] != s[fastIndex]) {
          mySet.erase(s[slowIndex++]);
        }
        ++slowIndex;
      }
      ++fastIndex;
    }
    return maxLength;
  }
};
// @lc code=end
