#ifndef PRINTINORDER_HPP_
#define PRINTINORDER_HPP_

#include <functional>
#include <mutex>

class Foo {
 private:
  std::mutex a, b;

 public:
  Foo() {
    a.lock();
    b.lock();
  }

  void first(const std::function<void()>& printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    a.unlock();
  }

  void second(const std::function<void()>& printSecond) {
    a.lock();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    b.unlock();
  }

  void third(const std::function<void()>& printThird) {
    b.lock();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};

#endif
