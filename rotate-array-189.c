// 映射结果到新数组
//
// 右移 K 个元素，得到的结果为：原数组倒数 K 个元素在新数组前 K 个位置，原数组前
// 面的元素在新数组最后面。
//
// 直接按照映射关系创建新数组。
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> res;
    k %= nums.size();
    copy_n(nums.cend() - k, k, back_inserter(res));
    copy_n(nums.cbegin(), nums.size() - k, back_inserter(res));
    nums = std::move(res);
  }
};

// 数组翻转
//
// 观察右移 K 位相当于将原数组划分为前后两部分并交换。
// 第一次翻转整个数组，相当于在不维持前后两部分内部次序的情况下进行交换。
// 第二三次翻转前后部分，相当于回复前后两部分的内部次序。
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() jk+ k);
    // std::reverse() 不允许第一个参数是尾后迭代器
    if (nums.begin() + k < nums.end()) {
      reverse(nums.begin() + k, nums.end());
    }
  }
};

// 环状替换
//
// 最直观的思路是每次右移数组 1 位，移动 K 次得到结果，为了避免 K 次移动的高额
// 成本，使用额外数组（第一种方法）。
// 
// 如果可以不移动整个数组，就把元素放到右移 K 位后的位置上，空间复杂度就会降低到
// O(1)。被迫使用额外数组的根源在于，将元素移动到右移 K 位的位置上后，该位置上的
// 元素会被覆盖。
//
// 使用环状替代可以避免元素被覆盖的情况。如下图，从 1 出发，将 1 移动到 3，再把
// 3 移动到 5，最后 5 移动到 1。这就完成子序列 1 3 5 的右移，接下来进行子序列 2
// 4 6 的右移。
//
//       -------
//       |     |
//       v     v
// -------     
// |     |
// v     v
// 1  2  3  4  5  6   K = 2
// ^           | 
// |           |
// -------------
//
// 每右移一圈，都有一个子序列完成右移操作，右移一圈的判断条件是回到起点，比如 1 3 5
// 从 1 出发，最终回到原点 1。
//
// 显然，当数组所有元素都右移过时，数组整体完成右移。
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int count = 0;
    int start = 0;
    while (count != nums.size()) {
      int next = start;
      int prev = nums[next];
      do {
        next = (next + k) % nums.size();
        int temp = nums[next];
        nums[next] = prev;
        ++count;
        prev = temp;
      } while (next != start);
      ++start;
    }
  }
};
