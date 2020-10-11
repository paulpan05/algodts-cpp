#include <algodts/algos.hpp>
#include <iostream>
#include <string>
#include <testing/catch.hh>
#include <thread>

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