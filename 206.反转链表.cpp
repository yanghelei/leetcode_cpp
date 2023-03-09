/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 20:43:14
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 21:00:54
 * @FilePath: /LeetCode/206.反转链表.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
  // 迭代法
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current) {
      ListNode* temp = current->next;
      current->next = prev;
      prev = current;
      current = temp;
    }
    return prev;
  }
};
// @lc code=end
