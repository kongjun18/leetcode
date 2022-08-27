// 字节跳动 Data 推荐系统 后端开发 二面面试题
//
// 双堆求数据流中位数
//
// 求数据流中位数意味着算法是在线算法，因此排序或划分就不可行了。求中位数实际上
// 是求第 N/2 小的数，因此只需要设置一个大小为 N/2 的大根堆，当大根堆大小大于 N/2
// 时，弹出堆顶元素。
//
// 数据流意味着无法提前获取数组长度，因此不能直接设置一个 N/2 的大根堆求中位数，
// 但是这个思路仍然有效。大根堆实际上维护了前 N/2 小的元素集合，再设置一个小根堆，
// 维护前 N/2 大的元素集合。尽可能让大根堆元素比小根堆多一个，当前大根堆元素恰好
// 比小根堆元素数量相同时，大根堆堆顶是前 N/2 小的元素，小根堆是前 N/2 大的元素，
// 两数平均就是中位数；当大根堆元素恰好比小根堆元素多一个时，大根堆堆顶是前 N/2+1
// 小的元素，它就是中位数。
class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    if (queMin.empty() || num <= queMin.top()) {
      queMin.push(num);
      if (queMax.size() + 1 < queMin.size()) {
        queMax.push(queMin.top());
        queMin.pop();
      }
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
