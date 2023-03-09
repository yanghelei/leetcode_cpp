/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 14:55:28
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 14:55:43
 * @FilePath: /LeetCode/20.有效的括号.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    vector<char> leftVec;

    unordered_map<char, char> myMap;
    myMap.insert(make_pair(')', '('));
    myMap.insert(make_pair('}', '{'));
    myMap.insert(make_pair(']', '['));

    stack<int> myStack;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        myStack.push(s[i]);
      else if (myStack.size() == 0)
        return false;
      else if (myStack.top() == myMap[s[i]])
        myStack.pop();
      else
        return false;
    }

    return myStack.size() == 0;
  }
};
// @lc code=end
