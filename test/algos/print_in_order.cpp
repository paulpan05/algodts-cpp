#include <iostream>
#include <string>
#include <thread>

#include "algodts/algos.hpp"
#include "testing/catch.hh"

using namespace std;

TEST_CASE("Multithreaded result print in order", "[thread_print_order]") {
  Foo obj;
  thread thread1(&Foo::first, &obj, []() {});
  thread thread2(&Foo::second, &obj, []() {});
  thread thread3(&Foo::third, &obj, []() {});
  thread1.join();
  thread2.join();
  thread3.join();
}