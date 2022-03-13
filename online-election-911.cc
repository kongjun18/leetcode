// 难点：
//     - 如何实现“票数相等时，最近被投票的候选人获胜”？
//     - 如何维持领先候选人？
// 技巧：
//     - upper_bound() - 1 求有序数组中小于某元素的位置。
//
// top 表示某时刻领先的候选人，因为时间是递增了，可以从初始时刻开始计算。
// 在 t 时刻，top 领先，那么在 t + 1 时刻，领先的候选人要么是 t 时刻的
// top，要么是 t + 1 时刻被投票的候选人。
//
// 获取某时刻领先的候选人只需要知道当前时刻被投票的候选人和前一时刻领先
// 的候选人，不需要知道更久以前的信息。利用这一不变量，可以一遍获取所有
// 时刻领先的候选人，这样就解决了第一个难点。
//
// 当前时刻候选人票数大于等于前一时刻领先的候选人，就认为当前时刻候选人
// 领先，解决了第二个难点。

class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) : times_(times) {
    unordered_map<int, int> person2vote;
    int top = -1;
    person2vote[top] = 0;
    for (int i = 0; i < persons.size(); ++i) {
      ++person2vote[persons[i]];
      if (person2vote[persons[i]] >= person2vote[top]) {
        top = persons[i];
      }
      top_.push_back(top);
    }
  }

  int q(int t) {
    auto pos = upper_bound(times_.cbegin(), times_.cend(), t) - 1;
    return top_[distance(times_.cbegin(), pos)];
  }

private:
  vector<int> times_;
  vector<int> top_;
};
