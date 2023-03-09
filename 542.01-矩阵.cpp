/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 18:02:54
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 18:50:23
 * @FilePath: /LeetCode/542.01-矩阵.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
 private:
  vector<int> direction{-1, 0, 1, 0, -1};

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int, int>> que;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0)
          que.push({i, j});
        else
          mat[i][j] = -1;
      }
    }

    while (!que.empty()) {
      // queue 进行存储，保证了最短传染路径（新的感染源在queue的尾部）
      int row = que.front().first;
      int col = que.front().second;
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int newrow = row + direction[i];
        int newcol = col + direction[i + 1];
        if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
            mat[newrow][newcol] == -1) {  // 遇到1(人)
          // 该1(人)离0(毒源)最近的距离 =
          // 新的毒源(mat[row][col])离最初毒源(0)的最短距离 + 1
          mat[newrow][newcol] = mat[row][col] + 1;
          que.push({newrow, newcol});
        }
      }
    }

    return mat;
  }
};
// @lc code=end
