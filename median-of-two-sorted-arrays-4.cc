// 算法思路：
// 最直观的算法是将两个有序数组归并为一个有序数组，然后取中位数。实际上，不需要
// 真的归并两数组，归并了 N/2-1 个数后就可以停止归并了，已经淘汰了 N/2-1 个数，
// 并且两数组有序，那么第 N/2 大的数肯定在剩余的两个数组开头。
//
// 可以看到，上述方法实际上是利用归并有序数组的算法，一次淘汰一个小于第 N/2 大
// 的数。可以通过一次淘汰多个数来加快淘汰过程，降低算法复杂度。
//
// 选取每个数组的前 k/2 个元素，每次淘汰其中一个数组的 k/2。淘汰 k/2 个元素后，
// 原先求第 k 大元素相当于求未淘汰区域的第 k/ 2 大的元素，重复此过程。
//
// 算法复杂度：
// 每次淘汰 k/2 个元素，即待淘汰的元素按照 k/2 的数率减少，相当于二分，时间复杂
// 度为 O(logN)，空间复杂度为 O(1)。
//
// 实现：
// 1. 划分点的选择
//    划分点下标为 idx+k/2-1，idx 代表数组中第一个未淘汰元素下标，k表示求两数组
//    的第 k 大的数。两个数组的可能淘汰区域加在一起公有 k/2+k/2 最多 k 个元素。
// 2. 中位数的位置
//    对于偶数，中位数在第 n/2 和 n/2+1 个数上；对于奇数，中位数在第 (n+1)/2 个
//    数上。
// 3. 避免下标越界，当划分点下标越界时，设置为数组末尾。
// 4. 边界条件条件为其中一个数组已被淘汰或需要淘汰的元素为 1。需要淘汰的元素为
//    1 时，两数组头部的元素的最小值是中位数，即两个数二选一，已经隐含了淘汰一
//    个元素。
// 5. 处理一个数组为空的情况。数组为空的情况可以包含在下标越界。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len = nums1.size() + nums2.size();
    if ((len % 2) == 0) {
      return (getKnthElem(nums1, nums2, len / 2) +
              getKnthElem(nums1, nums2, len / 2 + 1)) /
             2;
    }
    return getKnthElem(nums1, nums2, (len + 1) / 2);
  }

  double getKnthElem(const vector<int> &nums1, const vector<int> &nums2,
                     int k) {
    int idx1 = 0;
    int idx2 = 0;
    while (true) {
      if (idx1 >= nums1.size()) {
        return nums2[idx2 + k - 1];
      } else if (idx2 >= nums2.size()) {
        return nums1[idx1 + k - 1];
      } else if (k == 1) {
        return min(nums1[idx1], nums2[idx2]); // 选一个相当于驱逐了另一个
      }
      // 处理越界的情况！
      int new_idx1 = min(idx1 + k / 2 - 1, int(nums1.size() - 1));
      int new_idx2 = min(idx2 + k / 2 - 1, int(nums2.size() - 1));
      if (nums1[new_idx1] <= nums2[new_idx2]) {
        k -= new_idx1 - idx1 + 1; // 越界时淘汰的元素数量不是 k/2
        idx1 = new_idx1 + 1;
      } else {
        k -= new_idx2 - idx2 + 1;
        idx2 = new_idx2 + 1;
      }
    }
    return -1; // unreachable!!!
  }
};
int main() {
  vector<int> nums1{1};
  vector<int> nums2{2, 3, 4, 5, 6};
  cout << Solution{}.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
