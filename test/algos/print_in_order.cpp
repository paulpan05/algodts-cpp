#include <algodts/algos/print_in_order.hpp>
#include <sstream>
#include <string>
#include <testing/catch.hh>
#include <thread>

using namespace std;

TEST_CASE("Multithreaded result print in order", "[thread_print_order]") {
  Foo obj;
  vector<thread> thread_pool;
  ostringstream oss;

  function<void()> print_first = [&oss]() { oss << "first"; };
  function<void()> print_second = [&oss]() { oss << "second"; };
  function<void()> print_third = [&oss]() { oss << "third"; };

  thread_pool.emplace_back(&Foo::third, &obj, print_third);
  thread_pool.emplace_back(&Foo::second, &obj, print_second);
  thread_pool.emplace_back(&Foo::first, &obj, print_first);

  for (thread& t : thread_pool) {
    t.join();
  }

  REQUIRE(oss.str() == "firstsecondthird");
}
