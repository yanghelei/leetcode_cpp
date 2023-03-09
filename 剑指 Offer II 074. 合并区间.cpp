/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 14:43:54
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 14:44:03
 * @FilePath: /LeetCode/剑指 Offer II 074. 合并区间.cpp
 * @Description:
 */
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