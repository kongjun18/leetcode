// 双指针。
// 一种思路是将合法的元素存储到数组前面，遍历结束后，非法元素自然就在数组末尾。
// 另一种思路是直接将非法元素交换到数组末尾，这种办法常用于数组元素的快速删除。

// 同向双指针，将合法元素存储到数组前端。
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
      ++fast;
    }
    return slow;
  }
};

// 对撞指针，将非法元素交换到数组末尾。
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] == val) {
        if (nums[right] != val) {
          swap(nums[left++], nums[right]);
        }
        --right;
      } else {
        ++left;
      }
    }
    return right + 1;
  }
};
