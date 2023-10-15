// 字节跳动 Data 推荐系统 后端开发 二面面试题
//
// 双堆求数据流中位数
//
// 求数据流中位数意味着算法是在线算法，因此排序或划分就不可行了。求中位数实际上
// 是求第 N/2 小的数。思路是大根堆维护全局最小的 N/2 个元素，小根堆维护全局最大
// 的 N/2 个元素。最终中位数要么是两堆的一个堆顶，要么是两个堆顶的平均数。
//
// 算法的重点在于：
// 1) 维护全局最大/最小的 N/2 个元素
// 2) 维护两个堆的大小不超过 1。
//
// -------------
// \           /
//  \         /
//   \       /
//    \-----/
//     \   /
//      \ /
//       + 小根堆堆顶
//       + 大根堆堆顶
//      / \
//     /   \
//    /     \
//   /       \
//  /         \
// -------------
//
// 插入元素时，如果元素小于大根堆堆顶。1) 大根堆没有超过目标大小，直接插入大根堆。
// 2) 大根堆大于小根堆，说明其中有“最大的 N/2 个元素”中的元素，转移一个到小根堆。
// 这样，大根堆和小根堆分别维护全局最小/最大的 N/2 个元素。
//
// 可以让大根堆比小根堆多一个元素，这样当两堆数量不同时，大根堆堆顶总是中位数。
class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    // 小于大根堆根堆(最小的 N/2 个元素的最大值)，加入到大根堆。
    // 如果大根堆大小溢出，说明其中有在最大的 N/2 个元素中的元素。
    if (queMin.empty() || num <= queMin.top()) {
      queMin.push(num);
      // 大根堆比小根堆元素多 1 个，这样当两个堆数量不同时，中位数一定是大根堆堆顶。
      // 例如，5 个数的有序序列，中位数是第 3 个。
      if (queMax.size() + 1 < queMin.size()) {
        queMax.push(queMin.top());
        queMin.pop();
      }
    // 属于最大的 N/2 个元素
    } else {
      queMax.push(num);
      if (queMax.size() > queMin.size()) {
        queMin.push(queMax.top());
        queMax.pop();
      }
    }
  }

  double findMedian() {
    if (queMin.size() > queMax.size()) {
      return queMin.top();
    }
    return (queMin.top() + queMax.top()) / 2.0;
  }

private:
  priority_queue<int, vector<int>, less<int>> queMin;
  priority_queue<int, vector<int>, greater<int>> queMax;
};

// 这个实现中，两堆大小不超过 1，而且分离了元素插入和堆的重平衡（调整大小）。
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {

    }

    void addNum(int num) {
       if (maxHeap.empty() || num <= maxHeap.top()) {
           maxHeap.push(num);
       } else {
           minHeap.push(num);
       }

       if (maxHeap.size() > (minHeap.size() + 1)) {
           const auto elem = maxHeap.top();
           minHeap.push(elem);
           maxHeap.pop();
       }
       if (minHeap.size() > (maxHeap.size() + 1)) {
           const auto elem = minHeap.top();
           maxHeap.push(elem);
           minHeap.pop();
       }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return double(maxHeap.top() + minHeap.top())/2;
        }
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
