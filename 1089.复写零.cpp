/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 23:29:36
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 23:31:24
 * @FilePath: /LeetCode/1089.复写零.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    queue<int> myQueue;
    for (int i = 0; i < arr.size(); ++i) {
      myQueue.push(arr[i]);
      if (arr[i] == 0) {
        myQueue.push(0);
      }
      if (myQueue.size() >= arr.size()) break;
    }
    for (int i = 0; i < arr.size(); ++i) {
      arr[i] = myQueue.front();
      myQueue.pop();
    }
  }
};
// @lc code=end
