#include "algos/print_in_order.hpp"

using namespace std;

Foo::Foo() {
  a.lock();
  b.lock();
}

void Foo::first(function<void()> printFirst) {
  // printFirst() outputs "first". Do not change or remove this line.
  printFirst();
  a.unlock();
}

void Foo::second(function<void()> printSecond) {
  a.lock();
  // printSecond() outputs "second". Do not change or remove this line.
  printSecond();
  b.unlock();
}

void Foo::third(function<void()> printThird) {
  b.lock();
  // printThird() outputs "third". Do not change or remove this line.
  printThird();
}
