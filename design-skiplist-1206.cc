#include <bits/stdc++.h>
using namespace std;

// 跳表是多层链表，重点在于层次增长概率 randomLevel 的设置。
class Skiplist {
private:
  static const int max_level = 12;
  int level_;
  vector<Skiplist *> forward_;
  int val_;

public:
  explicit Skiplist() : level_(0), forward_(max_level, nullptr), val_(0) {}

  Skiplist(int level, int val)
      : level_(level), forward_(max_level, nullptr), val_(val) {}

  static void printPrecessors(const vector<Skiplist *> &precessors) {
    cout << precessors.size() << ": " << endl;
    for (const Skiplist *precessor : precessors) {
      cout << precessor->val_ << " ";
    }
    cout << endl;
  }

  static int randomLevel() {
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    int lv = 1;
    double P_FACTOR = 0.25;
    while (dis(gen) < P_FACTOR && lv < max_level) {
      lv++;
    }
    return lv;
    // srand(time(NULL));
    // int i = 1;
    // for (; i <= max_level; i++) {
    //   if (rand() % 2) {
    //     break;
    //   }
    // }
    // return i;
  }

  auto searchImpl(int target) -> vector<Skiplist *> {
    vector<Skiplist *> precessors;
    Skiplist *precessor = this;
    Skiplist *curr = nullptr;
    for (int level = level_; level; level--) {
      curr = precessor->forward_[level - 1];
      while (curr && curr->val_ < target) {
        precessor = curr;
        curr = precessor->forward_[level - 1];
      }
      precessors.push_back(precessor);
    }
    printPrecessors(precessors);
    return precessors;
  }

  bool search(int target) {
    const auto precessors = searchImpl(target);
    return !precessors.empty() && precessors.back()->forward_[0] &&
           precessors.back()->forward_[0]->val_ == target;
  }

  void add(int num) {
    auto precessors = searchImpl(num);
    int level = randomLevel();
    Skiplist *newNode = new Skiplist(level, num);
    for (int i = 0; i < level; i++) {
      Skiplist *precessor = nullptr;
      if (precessors.empty()) {
        precessor = this;
        level_++;
      } else {
        precessor = precessors.back();
        precessors.pop_back();
      }
      newNode->forward_[i] = precessor->forward_[i];
      precessor->forward_[i] = newNode;
    }
  }

  bool erase(int num) {
    auto precessors = searchImpl(num);
    if (!precessors.empty() && precessors.back()->forward_[0] &&
        precessors.back()->forward_[0]->val_ == num) {
      const auto target = precessors.back()->forward_[0];
      for (int i = 0; i < target->level_; i++) {
        const auto precessor = precessors.back();
        precessors.pop_back();
        precessor->forward_[i] = target->forward_[i];
      }
      return true;
    }
    return false;
  }
};

int main() {
  Skiplist *skiplist = new Skiplist();
  skiplist->add(1);
  skiplist->add(2);
  skiplist->add(3);
  assert(skiplist->search(0) == false); // 返回 false
  skiplist->add(4);
  assert(skiplist->search(1) == true);  // 返回 true
  assert(skiplist->erase(0) == false);  // 返回 false，0 不在跳表中
  assert(skiplist->erase(1) == true);   // 返回 true
  assert(skiplist->search(1) == false); // 返回 false，1 已被擦除
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
