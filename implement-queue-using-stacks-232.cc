// 备注：
//     阿里云一面试题
//
// 思路：
//     队列先进先出，栈先进后出，队列和栈的次序恰好反过来。为了模拟队列的次序，
//     最近进入队列的元素要放到栈低，但栈只允许将元素放到栈顶。
//     
//     只有当栈为空时，如栈的元素才在栈低，所以要确保元素入队时栈为空。通过双
//     栈实现队列，一个栈为存储数据的主栈，另一个是为了实现“元素如队时主栈为空”
//     而设置的辅助栈。
//
//     元素入队时，如果主栈不为空，全部 pop 到辅助栈中，元素压入主栈后再将辅助栈
//     中的元素 pop 到主栈中。

class MyQueue {
public:
  MyQueue() {}

  void push(int x) {
    while (!main_.empty()) {
      auxiliary_.push(main_.top());
      main_.pop();
    }
    main_.push(x);
    while (!auxiliary_.empty()) {
      main_.push(auxiliary_.top());
      auxiliary_.pop();
    }
  }

  int pop() {
    auto value = main_.top();
    main_.pop();
    return value;
  }

  int peek() { return main_.top(); }

  bool empty() { return main_.empty(); }

private:
  stack<int> main_;
  stack<int> auxiliary_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
