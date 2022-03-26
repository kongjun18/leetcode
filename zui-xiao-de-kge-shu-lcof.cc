// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
//
//
//
// 示例 1：
//
// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]
//
// 示例 2：
//
// 输入：arr = [0,1,2,1], k = 1
// 输出：[0]
//
//
//
// 限制：
//
//     0 <= k <= arr.length <= 10000
//         0 <= arr[i] <= 10000
//
//         来源：力扣（LeetCode）
//         链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k == 0) {
      return {};
    } else if (k >= arr.size()) {
      return arr;
    }
    int start = 0;
    int end = arr.size() - 1;
    int dvide_point = partition(arr, start, end);
    while (k != dvide_point) {
      if (dvide_point < k) {
        start = dvide_point + 1;
      } else {
        end = dvide_point - 1;
      }
      dvide_point = partition(arr, start, end);
    }
    vector<int> res;

    for (int i = 0; i < k; ++i) {
      res.push_back(arr[i]);
    }
    return res;
  }

private:
  int partition(vector<int> &arr, int start, int end) {
    if (end == start) {
      return start;
    }
    swap(arr[start + (random_device{}() % (end - start))], arr[end]);
    int privot = arr[end];
    int result = start;
    for (int i = start; i < end; ++i) {
      if (arr[i] < privot) {
        swap(arr[i], arr[result++]);
      }
    }
    swap(arr[result], arr[end]);
    return result;
  }
};
