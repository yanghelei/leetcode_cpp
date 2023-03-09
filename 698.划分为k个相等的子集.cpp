/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-08 22:55:18
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-08 23:21:36
 * @FilePath: /LeetCode/698.划分为k个相等的子集.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
 private:
  // 记录 k 个子集中数字之和
  vector<int> bucket;
  bool backTracking(vector<int>& nums, int startIndex, int target) {
    if (startIndex == nums.size()) return true;

    for (int i = 0; i < bucket.size(); ++i) {
      if (bucket[i] + nums[startIndex] > target) continue;
      // 如果当前子集的元素和与前一个子集的元素和相同，则跳过
      if (i > 0 && bucket[i] == bucket[i - 1]) continue;

      // 如果能够放入该元素，则放入
      bucket[i] += nums[startIndex];
      // 尝试放入 nums 的下一个元素
      if (backTracking(nums, startIndex + 1, target)) return true;
      // 撤销放入
      bucket[i] -= nums[startIndex];
    }
    // 如果 nums[startIndex] 无法放入所有子集
    return false;
  }

 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k > nums.size()) return false;
    // 使用 accumulate 求和
    int sum = accumulate(nums.begin(), nums.end());
    // sum 如果无法被均匀分成 k 份，则直接返回
    if (sum % k != 0) return false;
    // 从大到小放数字
    sort(nums.rbegin(), nums.rend());
    // 初始化 k 个 bucket
    bucket.resize(k);
    // 每个 bucket 的数字之和
    int target = sum / k;

    return backTracking(nums, 0, target);
  }
};
// @lc code=end
