// 使用原子标识位通信，first_run 为真则运行 first，second_run 为真则运行 second,
// 否则运行 third。
class Foo {
public:
  Foo() {}

  void first(function<void()> printFirst) {
    while (!first_run.load()) {
      this_thread::yield();
    }
    // printFirst() outputs "first_run". Do not change or remove this line.
    printFirst();
    first_run.store(false);
    second_run.store(true);
  }

  void second(function<void()> printSecond) {
    while (!second_run.load()) {
      this_thread::yield();
    }
    // printSecond() outputs "second_run". Do not change or remove this line.
    printSecond();
    second_run.store(false);
  }

  void third(function<void()> printThird) {
    while (first_run.load() || second_run.load()) {
      this_thread::yield();
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    first_run.store(true);
    second_run.store(false);
  }

private:
  atomic<bool> first_run{true};
  atomic<bool> second_run{false};
};
