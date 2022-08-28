// 思路见 stackoverflow
// [Find the pair across 2 arrays with kth largest sum](https://stackoverflow.com/questions/5212037/find-the-pair-across-2-arrays-with-kth-largest-sum)
//
// 当前最小数对下标分别为 (Ia, Ib)，那么下一个比它们大但是尽可能小的数对要么是 (Ia+1, Ib)，
// 要么是 (Ia, Ib+1)。
//
// 观察到这个不变量，虽然无法直接获取下一个大的数对，但是可以确定下一个尽可能小的大
// 数对所在的集合。这里可以使用小根堆维护这个集合，堆顶是集合中最小的数对，即我们要
// 寻找的下一个最小的数对。
//
// 每次都弹出堆顶元素（当前最小数对），压入下一次可能的两个最小数对，K 次后得到前 K
// 小的数对。
//
// 直接从 (0, 0) 开始压入数对，会存在重复压入数对的错误情况，比如 (3, 3)，可能从 (2, 3)
// 压入，也可能从 (3, 2) 压入，最终导致错误。最下面注释掉的代码就犯了这个错误。
//
// 解决这个问题有两种办法：
// - 记录下所有压入的数对，只压入未压入过的数对。
// - 压入 (i, 0)， i = 0,1,...k-1，pop 的过程中，只压入 B 数组前移后的下标。
//
// 为什么第二个方法可以避免重复压入数对？
// 考虑上面的示例，使用这种方法，pop 的过程中只压入 B 数组前移后的下标，因此(3,3)
// 一定是从 (3, 2) 压入的，避免了重复压入。
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> ans;
    auto cmp = [&nums1, &nums2](const pair<int, int> &lhs,
                                const pair<int, int> &rhs) {
      return nums1[lhs.first] + nums2[lhs.second] >
             nums1[rhs.first] + nums2[rhs.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (int i = 0; i < min(nums1.size(), k); ++i) {
      q.push({i, 0});
    }
    for (int i = 0; i < k && !q.empty(); ++i) {
      const auto item = q.top();
      q.pop();
      ans.push_back({nums1[item.first], nums2[item.second]});
      if (item.second + 1 < nums2.size()) {
        q.push({item.first, item.second + 1});
      }
    }
    return ans;
  }
};

// 这里存在向堆压入重复数对的情况，需要去重。
//
// class Solution {
// public:
//   vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
//                                      int k) {
//     vector<vector<int>> ans;
//     auto cmp = [&nums1, &nums2](const pair<int, int> &lhs,
//                                 const pair<int, int> &rhs) {
//       return nums1[lhs.first] + nums2[lhs.second] >
//              nums1[rhs.first] + nums2[rhs.second];
//     };
//     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
//         cmp);
//     q.push({0, 0});
//     for (int i = 0; i < k && !q.empty(); ++i) {
//       const auto item = q.top();
//       q.pop();
//       ans.push_back({nums1[item.first], nums2[item.second]});
//       if (item.first + 1 < nums1.size()) {
//         q.push({item.first + 1, item.second});
//         cout << item.first + 1 << " " << item.second << endl;
//       }
//       if (item.second + 1 < nums2.size()) {
//         q.push({item.first, item.second + 1});
//         cout << item.first << " " << item.second + 1 << endl;
//       }
//     }
//     return ans;
//   }
// };
