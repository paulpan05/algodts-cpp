#ifndef PRINTFOOBAR_HPP_
#define PRINTFOOBAR_HPP_

#include <condition_variable>
#include <functional>
#include <mutex>

class FooBar {
 private:
  int n;
  int state;
  std::condition_variable cv;
  std::mutex mtx;

 public:
  FooBar(int n) : n(n), state(0) {}

  void foo(std::function<void()>& printFoo) {
    for (int i = 0; i < n; i++) {
      // printFoo() outputs "foo". Do not change or remove this line.
      {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return state == 0; });
        printFoo();
        state = 1;
      }
      cv.notify_all();
    }
  }

  void bar(std::function<void()>& printBar) {
    for (int i = 0; i < n; i++) {
      // printBar() outputs "bar". Do not change or remove this line.
      {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return state == 1; });
        printBar();
        state = 0;
      }
      cv.notify_all();
    }
  }
};

#endif
