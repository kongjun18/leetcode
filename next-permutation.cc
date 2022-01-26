#include <algorithm>
#include <cassert>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

// 下一个序列必须大于当前序列，并且下一个序列相对于当前序列的“变化”要最小，
// 否则得到的可能是下下、下下下个序列。
//
// 观察到：
// 1. 如果后缀是递减的，那么不可能通过修改这个后缀的到下一个序列。一旦交换
// 后缀中的数，序列就会变小。
// 2. 当序列中前面的数小于后面的数时，交换这两个数得到更大的（下 N 个）序列。
//
// 从上面两个事实发现：
// 1. 需要交换的元素（左边）一定使得递减后缀被“打破”，即这个元素右边是递减序列。
// 2. 再从非递减序列中从后查找大于左边元素的最小的元素，交换这两个元素。这样得到的
// 序列大小变化最小。
// 3. 交换后相当于“开始了新生活”，交换位置（左边）的后缀应该要最小。后缀原先是递减的，
// 和大于交换位置（左边）的最小后缀元素交换（这个元素在后缀中的位置尽可能靠后）后，后缀
// 仍然是递减的，只要 reverse 就可以了，省去了排序的功夫。
//
// 总结：
// 关键在于寻找“交换位置”，这个位置打断递减后缀的元素。把序列想象成一条折线：
//
//             \
//              \
//          ---  \
//            ^   \
//            |    \
//          交换位置
//
// 然后在递减后缀中寻找大于交换位置的最小元素，两元素交换。
//             \
//            /
//          --   \-(交换位置原先的值)
//            ^   \
//            |    \
//          交换位置
//
// 交换后后缀的递减性仍然保持，要确保得到的序列尽可能小，所以后缀必须是递增的，所以翻转后缀。
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        // 最大的序列返回到最小的序列：
        // [3, 2, 1] --> [1, 2, 3]
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
     *     int i, j;
     *     for (i = nums.size() - 1; i > 0; --i) {
     *         for (j = i - 1; j >= 0; --j) {
     *             if (nums[j] < nums[i]) {
     *                 break;
     *             }
     *         }
     *         if (j >= 0) {
     *             break;
     *         }
     *     }
     *     if (i > 0) {
     *         swap(nums[i], nums[j]);
     *     } else {
     *         sort(nums.begin(), nums.end());
     *     }
     * }
     */
}
;
