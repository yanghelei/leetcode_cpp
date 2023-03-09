/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:49:54
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 00:50:02
 * @FilePath: /LeetCode/剑指 Offer II 105. 岛屿的最大面积.cpp
 * @Description:
 */
class Solution {
 private:
  int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
    if (grid[i][j] == 0) return 0;

    grid[i][j] = 0;
    int ans = 1;

    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; ++k) {
      ans += dfs(grid, i + x[k], j + y[k]);
    }
    return ans;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        int ans = dfs(grid, i, j);
        maxArea = max(maxArea, ans);
      }
    }
    return maxArea;
  }
};