//  双堆
//
//  保持双堆求中位数的逻辑不变，使用延迟删除策略，实现的要点是：
//  1. 确保 top() 返回未删除的元素。pop() 需要确保新堆顶是未删除元素。
//  2. 保证两堆的相对大小。Push 和 Erase 都可能导致大小失衡。
class SlidingWindow {
private:
  priority_queue<int, vector<int>, less<int>> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int maxHeapSize{0};
  int minHeapSize{0};
  unordered_map<int, int> deletedCount;

public:
  void Push(int val) {
    if (maxHeap.empty() || val <= maxHeap.top()) {
      maxHeap.push(val);
      maxHeapSize++;
    } else {
      minHeap.push(val);
      minHeapSize++;
    }
    makeBalance();
  }
  void Erase(int val) {
    deletedCount[val]++;
    if (val <= maxHeap.top()) {
      maxHeapSize--;
      prune(maxHeap);
    } else {
      minHeapSize--;
      prune(minHeap);
    }
    makeBalance();
  }

  double Median() const {
    if (maxHeapSize > minHeapSize) {
      return maxHeap.top();
    }
    return (double(maxHeap.top()) + minHeap.top()) / 2;
  }

private:
  template <typename Heap> void prune(Heap &heap) {
    while (!heap.empty() && deletedCount[heap.top()] > 0) {
      --deletedCount[heap.top()];
      if (deletedCount[heap.top()] == 0) {
        deletedCount.erase(heap.top());
      }
      heap.pop();
    }
  }
};

void makeBalance() {
  if (maxHeapSize > (minHeapSize + 1)) {
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    maxHeapSize--;
    minHeapSize++;
    prune(maxHeap);
  }
  if (minHeapSize > maxHeapSize) {
    maxHeap.push(minHeap.top());
    minHeap.pop();
    maxHeapSize++;
    minHeapSize--;
    prune(minHeap);
  }
}
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    SlidingWindow w;
    vector<double> ans;
    for (int start = 0, end = 0; end < nums.size(); end++) {
      w.Push(nums[end]);
      if ((end - start + 1) == k) {
        ans.push_back(w.Median());
        w.Erase(nums[start]);
        start++;
      }
    }
    return ans;
  }
};
