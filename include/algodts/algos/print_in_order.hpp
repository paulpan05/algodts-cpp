#ifndef PRINTINORDER_HPP_
#define PRINTINORDER_HPP_

#include <condition_variable>
#include <functional>
#include <mutex>

class Foo {
 private:
  std::mutex mtx;
  std::condition_variable cv;
  int now;

 public:
  Foo() : now(0) {}

  void first(std::function<void()>& printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [this]() { return now == 0; });
      now = 1;
      printFirst();
    }
    cv.notify_all();
  }

  void second(std::function<void()>& printSecond) {
    // printSecond() outputs "second". Do not change or remove this line.
    {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [this]() { return now == 1; });
      now = 2;
      printSecond();
    }
    cv.notify_all();
  }

  void third(std::function<void()>& printThird) {
    // printThird() outputs "third". Do not change or remove this line.
    {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [this]() { return now == 2; });
      now = 0;
      printThird();
    }
    cv.notify_all();
  }
};

#endif
