#ifndef PRINTINORDER_HPP_
#define PRINTINORDER_HPP_

#include <functional>
#include <mutex>

class Foo {
 private:
  std::mutex a, b;

 public:
  Foo();
  void first(std::function<void()> printFirst);

  void second(std::function<void()> printSecond);

  void third(std::function<void()> printThird);
};

#endif
