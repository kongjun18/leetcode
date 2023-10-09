// 滑动窗口
//
// 这道题是固定大小的滑动窗口，从左往右滑过去判断窗口平均数是否大于目标值即可。

class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int sum = 0;
    int num = 0;
    for (int start = 0, end = 0; end < arr.size(); ++end) {
      sum += arr[end];
      if (((end - start + 1) == k)) {
        if ((double(sum / k) >= threshold)) {
          num++;
        }
        sum -= arr[start++];
      }
    }
    return num;
  }
};
