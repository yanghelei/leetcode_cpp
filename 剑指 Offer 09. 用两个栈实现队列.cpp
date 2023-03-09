/*
 * @Author: Heyray.Yang
 * @Email: helei_yang@zju.edu.cn
 * @Date: 2023-03-09 00:50:28
 * @LastEditors: Heyray.Yang
 * @LastEditTime: 2023-03-09 00:50:37
 * @FilePath: /LeetCode/剑指 Offer 09. 用两个栈实现队列.cpp
 * @Description:
 */
class CQueue {
 private:
  stack<int> inStack, outStack;
  void in2out() {
    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

 public:
  CQueue() {}

  void appendTail(int value) { inStack.push(value); }

  int deleteHead() {
    if (outStack.empty()) {
      if (inStack.empty())
        return -1;
      else {
        in2out();
        int value = outStack.top();
        outStack.pop();
        return value;
      }
    } else {
      int value = outStack.top();
      outStack.pop();
      return value;
    }
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */