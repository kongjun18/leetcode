// 字节跳动 data 后端 三面
// 查找两个有序（递增）数组中相同的数。
//
// 算法来源：
// [How to Find Common Elements in Two Sorted Arrays]:
// https://www.baeldung.com/cs/arrays-common-elements

// 双指针：O(n+m)
vector<int> findCommonElems(const vector<int> &arr1, const vector<int> &arr2)
{
  vector<int> ans;
  int i = 0;
  int j = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] == arr2[j]) {
      ans.push_back(arr1[i]);
      ++i;
      ++j;
    } else if (arr1[i] < arr2[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  return ans;
}


// 二分搜索：O(n*log(m))

// 返回 target 下标，或最后一个小于 target 的元素的下标。
int binarySearch(const vector<int> &arr, int start, int end, int target) {
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return end;
}

vector<int> findCommonElems(const vector<int> &arr1, const vector<int> &arr2) {
  vector<int> ans;
  int i = 0;
  int j = 0;
  while (i < arr1.size() && j < arr2.size()) {
    i = binarySearch(arr2, i, arr1.size() - 1, arr2[j]);
    if (arr1[i] == arr2[j]) {
      ans.push_back(arr1[i]);
    }
    ++i;
    ++j;
  }
  return ans;
}
