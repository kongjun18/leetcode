// 小根堆求第 K 大的元素
//
// 小根堆维护全局最大的 K 个元素，堆顶就是第 K 大的元素。
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

// Hoare 划分
//
// partition 将区域 [left, right] 划分成 [left, k] 和 (k, right]，其中 [left, k]
// 所有元素均大于或等于 pivot，且 pivot 在此范围中；(k, right] 所有元素均小于或
// 等于 pivot。
//
// Lomuto 划分在大量元素相同的场景下会超时，因此只能用 Hoare 划分。Hoare 划分
// 返回的下标不是 pivot 的下标，但 pivot 在 [left, k]中，可以通过二分搜索不断
// 缩小 pivot 所在区域，当区域大小为 1 时，该元素就是 pivot。
class Solution {
private:
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        left--;
        right++;
        while (left < right) {
            do left++; while (nums[left]>pivot);
            do right--; while (nums[right]<pivot);
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        return right;
    }
public:
  int findKthLargest(vector<int> &nums, int k) {
      int left=0, right=nums.size()-1;
      while (true) {
          int mid = partition(nums, left, right);
          // 范围为 1，说明这就是 pivot（第 K 大元素）
          if (left == right) {
              return nums[left];
          }
          if ((mid+1) >= k) {
              right = mid;
          } else {
              left = mid + 1;
          }
      }
      // unreachable!!!
      return -1;
  }
};
