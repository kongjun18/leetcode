// 注意：
// - 正数字符串的比较
// - 使用随机的基准元素划分以避免超时
class Solution {
public:
  string kthLargestNumber(vector<string> &nums, int k) {
    if (k == 0) {
      return "";
    }

    int divide_point = partition(nums, 0, nums.size() - 1);
    int start = 0;
    int end = nums.size() - 1;
    while (k - 1 != divide_point) {
      if (divide_point < k - 1) {
        start = divide_point + 1;
      } else {
        end = divide_point - 1;
      }
      divide_point = partition(nums, start, end);
    }
    return nums[k - 1];
  }

private:
  bool cmp(const string &lhs, const string &rhs) {
    if (lhs.size() == rhs.size()) {
      return lhs > rhs;
    }
    return lhs.size() > rhs.size();
  }
  int partition(vector<string> &nums, int start, int end) {
    if (start == end) {
      return start;
    }
    swap(nums[start + (random_device{}() % (end - start))], nums[end]);
    int result = start;
    string privot = nums[end];
    for (int i = start; i < end; ++i) {
      if (cmp(nums[i], privot)) {
        swap(nums[i], nums[result++]);
      }
    }
    swap(nums[result], nums[end]);
    return result;
  }
};
