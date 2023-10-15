// 单调队列
//
// 单调队列用于在长度为 N 的序列中，求每个长度为 M 的区间的区间最值，复杂度为 O(N)。
//
// 单调队列维护一个双向队列，其中包含所有可能称为区间最值的值。双向队列中的值是
// 单调递增或递减的，这样就能在 O(1) 复杂度下获取区间最值。以题目求区间最大值（
// 对应递减的单调队列）为例，压入元素时删除队首所有更小的元素（它们不再可能是最
// 值），移动滑动窗口时只在移出窗口的元素是最值时（处于单调队列队首）从单调队列删除。

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
