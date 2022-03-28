// 维护前 k 大的元素，要用小顶堆，而且必须先 push 再 pop 多余元素。
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
