
#include <iostream>
#include <string>
#include <thread>

#include "algodts/algos.hpp"
#include "testing/catch.hh"

using namespace std;

TEST_CASE("Multithreaded result foobar alternate",
          "[thread_foobar_alternate]") {
  FooBar obj(1);
  thread thread1(&FooBar::foo, &obj, []() {});
  thread thread2(&FooBar::bar, &obj, []() {});
  thread1.join();
  thread2.join();
}