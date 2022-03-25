// 阿里巴巴补笔试：对于无序的长度为奇数的数组，求其中位数。
#include <algorithm>
#include <random>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
  int privot = arr[end];
  int result = 0;
  for (int i = 0; i < end - 1; ++i) {
    if (arr[i] < privot) {
      swap(arr[result++], arr[i]);
    }
  }
  swap(arr[result], arr[end]);
  return result;
}

int MiddleNumber(vector<int> &arr) {
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

int main() {
  vector<int> test(101);

  auto generator = std::mt19937{std::random_device{}()};
  for (int i = 0; i < 1000; ++i) {
    cout << i << endl;
    std::random_device rd{};
    std::generate(test.begin(), test.end(), generator);
    vector<int> other(test);
    int mid = MiddleNumber(test);
    sort(other.begin(), other.end());
    assert(mid == other[other.size() / 2]);
  }
  return 0;
}
