#include <functional>
#include <mutex>

Foo::Foo() {
  a.lock();
  b.lock();
}

void Foo::first(std::function<void()> printFirst) {
  // printFirst() outputs "first". Do not change or remove this line.
  printFirst();
  a.unlock();
}

void Foo::second(std::function<void()> printSecond) {
  a.lock();
  // printSecond() outputs "second". Do not change or remove this line.
  printSecond();
  b.unlock();
}

void Foo::third(std::function<void()> printThird) {
  b.lock();
  // printThird() outputs "third". Do not change or remove this line.
  printThird();
}