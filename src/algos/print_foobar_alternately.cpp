#include "algos/print_foobar_alternately.hpp"

#include <functional>

using namespace std;

FooBar::FooBar(int n) {
  this->n = n;
  a.lock();
}

void FooBar::foo(function<void()> printFoo) {
  for (int i = 0; i < n; i++) {
    b.lock();
    // printFoo() outputs "foo". Do not change or remove this line.
    printFoo();
    a.unlock();
  }
}

void FooBar::bar(function<void()> printBar) {
  for (int i = 0; i < n; i++) {
    a.lock();
    // printBar() outputs "bar". Do not change or remove this line.
    printBar();
    b.unlock();
  }
}