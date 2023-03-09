/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:31:56
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 00:48:16
 * @FilePath: /LeetCode/695.岛屿的最大面积.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
 private:
  int dfs(vector<vector<int>>& grid, int x, int y) {
    int area = 0;
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return area;
    if (grid[x][y] == 0)
      return area;
    else {
      ++area;
      grid[x][y] = 0;
      int arrX[4] = {1, -1, 0, 0};
      int arrY[4] = {0, 0, 1, -1};
      for (int i = 0; i < 4; ++i) {
        area += dfs(grid, x + arrX[i], y + arrY[i]);
      }
    }
    return area;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        maxArea = max(maxArea, dfs(grid, i, j));
      }
    }
    return maxArea;
  }
};
// @lc code=end
