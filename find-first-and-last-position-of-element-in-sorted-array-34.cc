// 1. 如何寻找终止的边界？
//   - 查找最右边的位置 1 2 2 3 4 查找 2
//         ^ ^
//         | |
//         l h
//     边界如上图。然后 l 往右走一位，l/h 重合，然后 h 往左边走一位，流程终止。
//
//     流程终止时变量的位置：
//     1 2 2 3 4 查找 2
//         ^ ^
//         | |
//         h l/m
//
//   - 查找最左边的位置
//     1 2 2 3 4 查找 2
//     ^ ^
//     | |
//     l h
//     边界如上图。然后 l 往右边走一位，l/h 重合，最后 h 往左边走一位，流程终止。
//
//     流程终止时变量的位置：
//     1 2 2 3 4 查找 2
//     ^ ^
//     | |
//     h l/m
//
// 2. 如何将向左查找和向右查找的逻辑合成一个函数？
//   查找最左边和最右边的位置，实际上只是 if 语句的条件不同，因此要合并向右/左查找
//   的条件。
//
//   引入一个“分支开关”，未开启时向右查找，开启时向左查找。
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

// 实现一个 Golang sort.Search() 分别搜索第一个 >= 和 > 的下标。
class Solution {
public:
    template<typename Predicate>
    // 返回 predicate 第一个 predicate 为假的下标
    int searchRangeImpl(vector<int>& nums, Predicate predicate) {
      int i = 0, j = nums.size() - 1;
      while (i <= j) {
        int mid = i + (j-i) / 2;
        if (predicate(nums[mid])) {
          i = i + 1;
        } else {
          j = j - 1;
        }
      }
      return i;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      // 第一个大于等于 target 的下标
      auto begin = searchRangeImpl(nums, [target] (const auto value) {
        return value < target;
      });
      if (!(begin < nums.size() && nums[begin] == target)) {
        begin = -1;
      }

      // 第一个大于 target 的下标
      auto end = searchRangeImpl(nums, [target] (const auto value) {
        return value <= target;
      });
      if (end > 0 && nums[end-1] == target) {
        end -= 1;
      } else {
        end = -1;
      }
      return {begin, end};
    }
};
