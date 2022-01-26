#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int left, int right)
    {
        /*
         * int privot = nums[right];
         * int result = left;
         * for (int i = left; i <= right; ++i) {
         *     if (nums[i] < privot) {
         *         swap(nums[result++], nums[i]);
         *     }
         * }
         * swap(nums[result], nums[right]);
         * return result;
         * int privot = nums[left];
         */

        // 错误
        /*
         * --left; ++right;
         * while (true) {
         *     while (++left && nums[left] < privot) {}
         *     while (--right && nums[right] > privot) {}
         *     if (left >= right) {
         *         return right;
         *     }
         *     swap(nums[left], nums[right]);
         */
        int privot = nums[left];
        int i = left, j = right + 1;
        while (true) {
            while (++i <= right && nums[i] < privot) {}
            while (--j >= left && nums[j] > privot) {}
            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        nums[left] = nums[j];
        nums[j] = privot;
        return j;
    }
}
}

int solution1(vector<int>& nums, int k)
{
    if (nums.empty() || k < 1) {
        return {};
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int pos = partition(nums, left, right);
        if (pos == nums.size() - k) {
            return nums[pos];
        } else if (pos < nums.size() - k) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}

int solution2(vector<int>& nums, int k)
{
    if (nums.empty() || k < 1) {
        return -1;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (const auto num : nums) {
        auto size = q.size();
        if (size < k) {
            q.push(num);
        } else if (num > q.top()) {
            q.pop();
            q.push(num);
        }
    }
    return q.top();
}

int findKthLargest(vector<int>& nums, int k)
{
    return solution1(nums, k);
}
}
;

int main(void)
{
    vector nums1 = { 3, 2, 1, 5, 6, 4 };
    vector nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    vector nums3 = { 7, 6, 5, 4, 3, 2, 1 };
    assert(5 == Solution {}.findKthLargest(nums1, 2));
    assert(4 == Solution {}.findKthLargest(nums2, 4));
    assert(6 == Solution {}.findKthLargest(nums3, 2));
    return 0;
}
