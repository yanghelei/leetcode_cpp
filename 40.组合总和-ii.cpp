/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 21:40:28
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 21:40:50
 * @FilePath: /LeetCode/40.组合总和-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& candidates, int target, int sum,
                    int startIndex) {
    if (sum == target) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex;
         i < candidates.size() && sum + candidates[i] <= target; i++) {
      // 要对同一树层使用过的元素进行跳过
      if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
      sum += candidates[i];
      path.push_back(candidates[i]);
      // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
      backtracking(candidates, target, sum, i + 1);
      sum -= candidates[i];
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    path.clear();
    result.clear();
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return result;
  }
};
// @lc code=end
