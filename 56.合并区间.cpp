/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 21:46:47
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 21:46:53
 * @FilePath: /LeetCode/56.合并区间.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    int minInterval = intervals[0][0];
    int maxInterval = intervals[0][1];
    for (auto& interval : intervals) {
      if (interval[0] > maxInterval) {
        result.push_back(vector<int>{minInterval, maxInterval});
        minInterval = interval[0];
      }
      maxInterval = max(maxInterval, interval[1]);
    }
    result.push_back(vector<int>{minInterval, maxInterval});
    return result;
  }
};
// @lc code=end
