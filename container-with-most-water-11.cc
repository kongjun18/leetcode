// 贪心 + 双指针
//
// 容器的容量取决于两边的高度和距离，因此从距离最远的位置（最左最右两个指针）开始。
// 容器的容量受限于最低的一边的高度，如果一边更低，那么应该移动该边试图找到更高
// 的边，在此过程中记录容量最大值。
class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int capacity = INT_MIN;
    while (left < right) {
      capacity =
          max(capacity, (right - left) * min(height[left], height[right]));
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return capacity;
  }
};
