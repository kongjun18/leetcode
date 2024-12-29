// 这道题是抖音搜索部门Leader面编程题。
//
// 解题的关键在于意识到“二分后，必有一边有序”或“二分搜索只要求二分后，可以确定
// 目标必在其中一边”。
//
// 将数组想象成一条非递减的折线，在某个高度画水平线，将此折现划分为两条线，水平
// 线以上的部分向左平移。可以发现，二分后左右两部分必有一边是有序的（非递减），
// 如果目标在其中一个有序部分中，则搜索返回缩小到该有序部分，否则在另一边的无序
// 部分中搜索。该无序部分虽然整体无序，但二分后也必有一边有序。
//
// 从“二分搜索只要求二分后，可以确定目标必在其中一边”的角度看，二分后目标必在其
// 中一部分，那么只需要根据条件（是否在有序部分中）判断去哪一边搜索即可。
class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.size() < 0) {
      return -1;
    } else if (nums.size() == 1) {
      return target == nums[0] ? 0 : -1;
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      // mid 位于“第一段”
      // 有序数组视作“第二段”不存在，因此这里必须是 <=
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[nums.size() - 1]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};
