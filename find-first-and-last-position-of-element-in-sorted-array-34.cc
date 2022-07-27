// 1. 如何寻找终止的边界？
//   - 查找最右边的位置
//     1 2 2 3 4 查找 2
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
