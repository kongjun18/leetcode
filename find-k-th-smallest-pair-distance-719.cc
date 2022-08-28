// 使用堆维护局部的最小数对差值。思路见 find-k-pairs-with-smallest-sums-373，但
// 这里超时。

// class Solution {
// public:
//   int smallestDistancePair(vector<int> &nums, int k) {
//     sort(nums.begin(), nums.end());
//     auto cmp = [&nums](const pair<int, int> &lhs, const pair<int, int> &rhs) {
//       return nums[lhs.second] - nums[lhs.first] >
//              nums[rhs.second] - nums[rhs.first];
//     };
//     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
//         cmp);
//     for (int i = 1; i < min(int(nums.size()), k + 1); ++i) {
//       q.push(make_pair(i - 1, i));
//     }
//     int ans = 0;
//     for (int i = 0; i < k && !q.empty(); ++i) {
//       const auto p = q.top();
//       q.pop();
//       ans = nums[p.second] - nums[p.first];
//       if (p.second + 1 < nums.size()) {
//         q.push(make_pair(p.first, p.second + 1));
//       }
//     }
//     return ans;
//   }
// };

// 二分搜索
//
// 将数对差值视作二分搜索的对象，对于差值 D，搜索数组中差值小于 D 的数对数量，如果
// 数对数量少于 K，说明差值 D 太小，否则太大。一直二分搜索，知道找到某个差值 D，
// 数组中差值为 D 的数对数量为 K。
//
// 坑：使得数组中恰好有 K 个数对差值小于 D 的 D，未必是要求的第 K 小的数对差值。
// 因为这个 D 是自己设置的目标差值，不是数组中已经存在的数对差值，需要不断二分逼近
// 真实的差值，即二分的过程尽可能往左边走，搜索小的 D。
class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.back() - nums.front();
    int mid = 0;
    while (left <= right) {
        mid = left + (right-left) / 2;
        int cnt = 0;
        // 计算数组中有多少个差值小于 mid 的数对
        for (int i = 1; i < nums.size(); ++i) {
            cnt += i - distance(nums.cbegin(), lower_bound(nums.cbegin(), nums.cbegin()+i, nums[i]-mid));
        }
        // 不断搜索尽可能小的目标差值
        if (cnt < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // 考虑边界（left==right）。
    // 如果 cnt<k，说明该 D 过小，右边才是正确的差值。
    // 如果 cnt>=k，说明已经搜索到目标差值。
    return left;
  }
};
