// 思路：
//     队列先进先出，栈先进后出，队列和栈的次序恰好反过来。为了模拟栈的次序，新
//     入栈的元素要放到队头，因为队列不支持插入元素到对头，直接把队列中新入栈元素
//     之前的元素出队放到队尾。
class MyStack {
public:
  MyStack() {}

  void push(int x) {
    queue_.push(x);
    int count = queue_.size();
    while (--count) {
      auto value = queue_.front();
      queue_.pop();
      queue_.push(value);
    }
  }

  int pop() {
    auto value = queue_.front();
    queue_.pop();
    return value;
  }

  int top() { return queue_.front(); }

  bool empty() { return queue_.empty(); }

private:
  queue<int> queue_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
