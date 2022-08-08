// 快慢指针
//
// 慢指针指向写入位置，快指针一直向前走，发现不重复的元素就写入到慢指针指向的位
// 置，递增慢指针。
//
// 发现不重复的元素，指当前遍历到的元素和保留下来的元素（slow-1指向的元素）不同。
// 在这里可以通过 nums[fast-1] 和 nums[fast] 是否相同判断元素是否重复，但这只是
// 保留一个重复元素的特例，对于姊妹题 remove-duplicates-from-sorted-array-ii-80，
// 就必须使用 slow 和 fast 指向的元素比较。

// slow/fast 从下标 0 开始，不用判断数组长度是否为 0。
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    int fast = 0;
    for (; fast < nums.size(); ++fast) {
      if (fast == 0 || nums[fast - 1] != nums[fast]) {
        nums[slow++] = nums[fast];
      }
    }
    return slow;
  }
};

// slow/fast 从 1 开始，需要判断数组长度是否大于 0，但是不需要考虑 fast-1 是否
// 越界。
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int fast = 1, slow = 1;
    while (fast < nums.size()) {
      if (nums[fast] != nums[fast - 1]) {
        nums[slow] = nums[fast];
        ++slow;
      }
      ++fast;
    }
    return slow;
  }
};
