class Solution {
private:
  bool overlap(const vector<int> &a, const vector<int> &b) {
    return !(a[1] < b[0] || b[1] < a[0]);
  }

public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    if (intervals.empty()) {
      return {};
    }
    // Extend monoatomically
    sort(intervals.begin(), intervals.end(),
         [](const auto &lhs, const auto &rhs) { return lhs[0] < rhs[0]; });

    vector<vector<int>> ans;
    vector<int> merged;
    for (int i = 0; i < intervals.size(); i++) {
      // Note: compare the current interval with previous merged interval
      if (i == 0 || !overlap(merged, intervals[i])) {
        merged = intervals[i];
        ans.push_back(merged);
        continue;
      }
      const auto &interval = intervals[i];
      // Extend
      merged = {min(merged[0], interval[0]), max(merged[1], interval[1])};
      ans.back() = merged;
    }

    return ans;
  }
};
