/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 19:04:06
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 19:04:28
 * @FilePath: /LeetCode/217.存在重复元素.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> mySet;
    for (auto& num : nums) {
      if (mySet.find(num) != mySet.end()) return true;
      mySet.insert(num);
    }
    return false;
  }
};
// @lc code=end
