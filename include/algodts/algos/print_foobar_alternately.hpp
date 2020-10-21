#ifndef PRINTFOOBAR_HPP_
#define PRINTFOOBAR_HPP_

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

#include <algodts/algos/impl/print_foobar_alternately.ipp>

#endif
