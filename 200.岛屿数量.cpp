/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 19:04:53
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 19:05:04
 * @FilePath: /LeetCode/200.岛屿数量.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
 private:
  void dfs(vector<vector<char>>& grid, int x, int y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
      return;
    }
    if (grid[x][y] == '0')
      return;
    else {
      grid[x][y] = '0';
      int arrX[4] = {1, -1, 0, 0};
      int arrY[4] = {0, 0, 1, -1};
      for (int i = 0; i < 4; ++i) {
        dfs(grid, x + arrX[i], y + arrY[i]);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++ans;
          dfs(grid, i, j);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
