#include "algos/print_in_order.hpp"

#include <iostream>
#include <string>
#include <thread>

#include "testing/catch.hh"

using namespace std;

void printFirst() { cout << "a"; }
void printSecond() { cout << "b"; }
void printThird() { cout << "c"; }

TEST_CASE("Multithreaded result print in order", "[thread_print_order]") {
  Foo obj;
  thread thread1(&Foo::first, &obj, printFirst);
  thread thread2(&Foo::second, &obj, printSecond);
  thread thread3(&Foo::third, &obj, printThird);
  thread1.join();
  thread2.join();
  thread3.join();
}