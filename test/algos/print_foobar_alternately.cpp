
#include "algos/print_foobar_alternately.hpp"

#include <iostream>
#include <string>
#include <thread>

#include "testing/catch.hh"

using namespace std;

void printFoo() {  // cout << "foo";
}
void printBar() {  // cout << "bar";
}

TEST_CASE("Multithreaded result foobar alternate",
          "[thread_foobar_alternate]") {
  string result;

  FooBar obj(1);
  thread thread1(&FooBar::foo, &obj, printFoo);
  thread thread2(&FooBar::bar, &obj, printBar);
  thread1.join();
  thread2.join();
}