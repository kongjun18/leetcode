// 1. stop 后必须置 zero_run 为 false，否则 even 或 odd 线程可能永不退出。
// 2. 设置 stop 标志未时要判断是否所有小于等于 n 的奇偶数都打印完毕。
class ZeroEvenOdd {
private:
  int n;
  atomic<bool> stop{false};
  atomic<bool> zero_run{true};
  atomic<bool> odd_run{true};

public:
  ZeroEvenOdd(int n) { this->n = n; }

  void zero(function<void(int)> printNumber) {
    while (!stop.load()) {
      if (zero_run.load()) {
        printNumber(0);
        zero_run.store(false);
      } else {
        this_thread::yield();
      }
    }
    // 注意：stop 后必须置 zero_run 为 false，否则 even 或 odd
    // 线程可能永不退出。
    zero_run.store(false);
  }

  void even(function<void(int)> printNumber) {
    int i = 2;
    while (i <= n) {
      if (zero_run.load() || odd_run.load()) {
        this_thread::yield();
        continue;
      }
      printNumber(i);
      i += 2;
      zero_run.store(true);
      odd_run.store(true);
    }
    stop.store(n % 2 == 0);
  }

  void odd(function<void(int)> printNumber) {
    int i = 1;
    while (i <= n) {
      if (zero_run.load() || !odd_run.load()) {
        this_thread::yield();
        continue;
      }
      printNumber(i);
      i += 2;
      zero_run.store(true);
      odd_run.store(false);
    }
    stop.store(n % 2 == 1);
  }
};
