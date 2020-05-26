#include "algos/print_in_order.hpp"

#include <string>
#include <thread>

#include "testing/catch.hh"

using namespace std;

string result;
void printFirst() { result += "a"; }
void printSecond() { result += "b"; }
void printThird() { result += "c"; }

Foo obj;

TEST_CASE("Multithreaded result", "[thread_print_order]") {
  thread thread1(&Foo::first, &obj, printFirst);
  thread thread2(&Foo::second, &obj, printSecond);
  thread thread3(&Foo::third, &obj, printThird);
  thread1.join();
  thread2.join();
  thread3.join();
  REQUIRE(result == "abc");
}