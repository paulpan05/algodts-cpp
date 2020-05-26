#ifndef PRINTFOOBARALTERNATELY_HPP_
#define PRINTFOOBARALTERNATELY_HPP_

#include <functional>
#include <mutex>

class FooBar {
 private:
  int n;
  std::mutex a, b;

 public:
  FooBar(int n);

  void foo(std::function<void()> printFoo);

  void bar(std::function<void()> printBar);
};

#endif