/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 19:33:24
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 20:28:10
 * @FilePath: /LeetCode/15.三数之和.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<int> myNums = nums;
    sort(myNums.begin(), myNums.end());
    vector<vector<int>> result;
    for (int i = 0; i < myNums.size(); ++i) {
      if (i > 0 && myNums[i] == myNums[i - 1]) {
        continue;
      }
      int target = -myNums[i];

      // 在 [i, myNums.size() - 1] 上找到两数之和等于 -myNums[i]
      int k = myNums.size() - 1;
      for (int j = i + 1; j < myNums.size(); ++j) {
        if (j > i + 1 && myNums[j] == myNums[j - 1]) {
          continue;
        }
        while (j < k && myNums[j] + myNums[k] > target) {
          --k;
        }
        if (j == k) break;
        if (myNums[j] + myNums[k] == target) {
          result.push_back({myNums[i], myNums[j], myNums[k]});
        }
      }
    }
    return result;
  }
};
// @lc code=end
