// 这道题微软暑期实习一面做过！！！
//
// 最简单的思路是两层循环：
// (1)遍历 nums1 中的元素，对于任意一个元素。
// (2)用 nums1 中的其他元素替换它，计算差值。两层循环之后，就找到了最小值。
//
// 上面的算法复杂度为 O(n*n)。遍历 nums1 的元素是必须的，所以只能从“查找能替换后
// 使差值最小的元素”入手。使用二分查找将这个过程从 O(n) 降低到 O(log(n))，总体
// 复杂度最终将降低到 O(n*log(n))。
//
// 显然，两个数最接近时，差的绝对值最小。
class Solution {
public:
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    long long sum = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      sum += abs(nums1[i] - nums2[i]);
    }
    vector<int> nums(nums1);
    sort(nums.begin(), nums.end());

    long long min_sum = sum;
    for (int i = 0; i < nums2.size(); ++i) {
      int min = INT_MAX;
      int left = 0, right = nums2.size() - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums2[i]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
        min = std::min(min, abs(nums2[i] - nums[mid]));
      }
      min_sum = std::min(min_sum, sum - abs(nums1[i] - nums2[i]) + min);
    }
    return min_sum % (static_cast<int>(1e9 + 7));
  }
};
