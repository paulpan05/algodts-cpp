#include "algos/print_in_order.hpp"

using namespace std;

Foo::Foo() {
  Foo::a.lock();
  Foo::b.lock();
}

void Foo::first(function<void()> printFirst) {
  // printFirst() outputs "first". Do not change or remove this line.
  printFirst();
  Foo::a.unlock();
}

void Foo::second(function<void()> printSecond) {
  Foo::a.lock();
  // printSecond() outputs "second". Do not change or remove this line.
  printSecond();
  Foo::b.unlock();
}

void Foo::third(function<void()> printThird) {
  Foo::b.lock();
  // printThird() outputs "third". Do not change or remove this line.
  printThird();
}
