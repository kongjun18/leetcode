// 1. 单调队列
//
// 单调队列维护一个双向队列，其中包含所有可能称为区间最值的值。
// 双向队列中的值是单调递增或递减的，这样就能在 O(1) 复杂度下获取区间最值。
//
// 关键在于在队列中维护所有可能成为新的最大值的元素。只要新遇到的元素比队列末尾
// 的大，则队列中更小的元素不可能成为新的最大值，所以右移滑动窗口时删除队尾所有
// 比新元素小的元素。这样，队列里的元素一定是递减的（如果有递增则小的元素可以删除）。
// 右移滑动窗口后，队头（最大值）可能被移除了滑动窗口，因此要在移动滑动窗口时检查
// 队头是否超过滑动窗口左界限，可以通过存储下标实现。
//
// 2. 大根堆
// 逻辑和单调队列类似。如果最大值不再窗口中，则弹出堆顶直到最大值在窗口中。
//
// 在 Queue 中封装单调队列
class Solution {
public:
    class Queue {
    private:
        deque<int> q_;
    public:
        void push(int val) {
            while (!q_.empty() && val > q_.back()) {
                q_.pop_back();
            }
            q_.push_back(val);
        }
        void erase(int val) {
            if (!q_.empty() && val >= q_.front() ) {
                q_.pop_front();
            }
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        Queue q;
        for (int start = 0, end = 0; end < nums.size(); end++) {
            q.push(nums[end]);
            if ((end-start+1) == k) {
                ans.push_back(q.front());
                q.erase(nums[start]);
                start++;
            }
        }
        return ans;
    }
};

// 不封装单调队列
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      while (!q.empty() && nums[i] > q.back()) {
        q.pop_back();
      }
      q.push_back(nums[i]);
    }
    res.push_back(q.front());
    for (int i = k; i < nums.size(); ++i) {
      if (nums[i - k] == q.front()) {
        q.pop_front();
      }
      while (!q.empty() && nums[i] > q.back()) {
        q.pop_back();
      }
      q.push_back(nums[i]);
      res.push_back(q.front());
    }
    return res;
  }
};
