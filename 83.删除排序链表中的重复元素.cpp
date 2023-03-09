/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 22:09:49
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 22:09:55
 * @FilePath: /LeetCode/83.删除排序链表中的重复元素.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* cur = head;
    while (cur->next != nullptr) {
      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
        continue;
      }
      cur = cur->next;
    }
    return head;
  }
};
// @lc code=end
