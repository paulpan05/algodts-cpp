#include <algodts/algos/print_foobar_alternately.hpp>
#include <iostream>
#include <sstream>
#include <testing/catch.hh>
#include <thread>

using namespace std;

TEST_CASE("Multithreaded result foobar alternate",
          "[thread_foobar_alternate]") {
  FooBar obj(3);
  vector<thread> thread_pool;
  ostringstream oss;

  function<void()> print_foo = [&oss]() { oss << "foo"; };
  function<void()> print_bar = [&oss]() { oss << "bar"; };

  thread_pool.emplace_back(&FooBar::bar, &obj, ref(print_bar));
  thread_pool.emplace_back(&FooBar::foo, &obj, ref(print_foo));

  for (thread& t : thread_pool) {
    t.join();
  }

  REQUIRE(oss.str() == "foobarfoobarfoobar");
}
