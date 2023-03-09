/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 22:13:06
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 22:13:12
 * @FilePath: /LeetCode/76.最小覆盖子串.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
 public:
  unordered_map<char, int> tMap, cMap;

  string minWindow(string s, string t) {
    // 遍历 t，将其放入哈希表中
    for (int i = 0; i < t.size(); ++i) {
      ++tMap[t[i]];
      // cMap[t[i]] = 0;
    }

    int minLength = s.size() + 1;
    int minL = 0;

    int slowIndex = 0;
    int fastIndex = 0;
    while (fastIndex < s.size()) {
      if (tMap.find(s[fastIndex]) != tMap.end()) {
        ++cMap[s[fastIndex]];
        while (checkSatisfy(cMap)) {
          int length = fastIndex - slowIndex + 1;
          if (length < minLength) {
            minL = slowIndex;
            minLength = length;
          }
          if (tMap.find(s[slowIndex]) != tMap.end()) {
            --cMap[s[slowIndex]];
          }
          ++slowIndex;
        }
      }
      ++fastIndex;
    }
    return minLength == s.size() + 1 ? "" : s.substr(minL, minLength);
  }

 private:
  bool checkSatisfy(unordered_map<char, int>& store) {
    for (const auto& p : tMap) {
      if (p.second > store[p.first]) return false;
    }
    return true;
  }
};
// @lc code=end
