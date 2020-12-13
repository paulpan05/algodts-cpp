#include <algodts/algos/print_h2o.hpp>
#include <sstream>
#include <string>
#include <testing/catch.hh>
#include <thread>

using namespace std;

TEST_CASE("Multithreaded result print H2O", "[thread_print_h2o]") {
  H2O obj;
  vector<thread> thread_pool;
  ostringstream oss;

  function<void()> print_h = [&oss]() { oss << 'H'; };
  function<void()> print_o = [&oss]() { oss << 'O'; };

  for (int i = 0; i < 20; ++i) {
    thread_pool.emplace_back(&H2O::hydrogen, &obj, ref(print_h));
  }
  for (int j = 0; j < 10; ++j) {
    thread_pool.emplace_back(&H2O::oxygen, &obj, ref(print_o));
  }

  for (thread& t : thread_pool) {
    t.join();
  }

  REQUIRE(oss.str() == "OHHOHHOHHOHHOHHOHHOHHOHHOHHOHH");
}