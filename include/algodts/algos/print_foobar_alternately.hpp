#ifndef PRINTFOOBAR_HPP_
#define PRINTFOOBAR_HPP_

#include <functional>
#include <mutex>

class FooBar {
 private:
  int n;
  std::mutex a, b;

 public:
  FooBar(int n) : n(n) { a.lock(); }

  void foo(const std::function<void()>& printFoo) {
    for (int i = 0; i < n; i++) {
      b.lock();
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      a.unlock();
    }
  }

  void bar(const std::function<void()>& printBar) {
    for (int i = 0; i < n; i++) {
      a.lock();
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      b.unlock();
    }
  }
};

#endif
