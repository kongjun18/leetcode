// 阿里巴巴补笔试：对于无序的长度为奇数的数组，求其中位数。
//
// 他妈的 std::partition()，返回的不是 pivot！！！
// std::stable_partition() 返回的才是 pivot 的迭代器！！！
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
  int privot = arr[end];
  int result = 0;
  for (int i = 0; i < end; ++i) {
    if (arr[i] < privot) {
      swap(arr[result++], arr[i]);
    }
  }
  swap(arr[result], arr[end]);
  return result;
}

int MedianHandWritten(vector<int> &arr) {
  int start = 0;
  int end = arr.size() - 1;
  int middle = arr.size() / 2;
  int index = partition(arr, start, end);
  while (middle != index) {
    if (index < middle) {
      start = index + 1;
    } else {
      end = index - 1;
    }
    index = partition(arr, start, end);
  }
  return arr[middle];
}

int MedianSTL(vector<int> &arr) {
  auto middle = std::next(arr.begin(), arr.size() / 2);
  auto begin = arr.begin();
  auto end = arr.end();
  auto index = std::stable_partition(
      begin, end, [pivot = *begin](int val) { return val < pivot; });
  while (index != middle) {
    if (index < middle) {
      begin = std::next(index, 1);
    } else {
      end = index;
    }
    index = std::stable_partition(
        begin, end, [pivot = *begin](int val) { return val < pivot; });
  }
  return *middle;
}

int main() {
  vector<int> test(101);

  auto generator = std::mt19937{std::random_device{}()};
  for (int i = 0; i < 1000; ++i) {
    std::random_device rd{};
    std::generate(test.begin(), test.end(), generator);
    vector<int> other(test);
    int mid = MedianHandWritten(test);
    sort(other.begin(), other.end());
    assert(mid == other[other.size() / 2]);
  }
  cout << "MedianHandWritten() passes test" << endl;

  for (int i = 0; i < 1000; ++i) {
    std::random_device rd{};
    std::generate(test.begin(), test.end(), generator);
    vector<int> other(test);
    int mid = MedianSTL(test);
    sort(other.begin(), other.end());
    assert(mid == other[other.size() / 2]);
  }
  cout << "MedianSTL() passes test" << endl;
  return 0;
}
