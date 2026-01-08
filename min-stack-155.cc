// Auxiliary stack
class MinStack {
private:
    stack<int> values;
    stack<int> mins;
public:
    MinStack() {
    }

    void push(int val) {
        values.push(val);
        int minimal = min(val, mins.empty() ? INT_MAX : mins.top());
        mins.push(minimal);
    }

    void pop() {
        values.pop();
        mins.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
