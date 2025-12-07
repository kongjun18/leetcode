class CustomStack {
    vector<int> stack_;
    int capacity_;
public:
    CustomStack(int maxSize) {
        capacity_ = maxSize;
    }

    void push(int x) {
        if (stack_.size() == capacity_) {
            return;
        }
        stack_.push_back(x);
    }

    int pop() {
        if (stack_.empty()) {
            return -1;
        }

        int val = stack_.back();
        stack_.pop_back();
        return val;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < stack_.size(); i++) {
            stack_[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
