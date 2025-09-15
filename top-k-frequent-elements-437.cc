// 维护前 k 大的元素，当 heap 大小超过 k 时，需要把最小的元素弹出来，因此需要用小根堆。
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> num2frequency;
    for (int i : nums) {
      ++num2frequency[i];
    }
    auto cmp = [&num2frequency](int lhs, int rhs) {
      return num2frequency[lhs] > num2frequency[rhs];
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    for (auto elem : num2frequency) {
      q.push(elem.first);
      if (q.size() > k) {
        q.pop();
      }
    }

    vector<int> res(k);
    for (int i = 0; i < k; ++i) {
      res[i] = q.top();
      q.pop();
    }
    return res;
  }
};
