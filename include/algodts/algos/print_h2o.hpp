#ifndef PRINTH2O_HPP_
#define PRINTH2O_HPP_

#include <condition_variable>
#include <functional>
#include <mutex>

class H2O {
 public:
  int h_count;
  int ready;
  std::mutex mtx_h, mtx_o;
  std::condition_variable cond_h, cond_o;
  H2O() : h_count(0), ready(0) {}

  void hydrogen(std::function<void()> releaseHydrogen) {
    std::unique_lock<std::mutex> lck(mtx_h);
    while (ready % 3 == 0) {
      cond_h.wait(lck);
    }
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    ++h_count;
    ++ready;
    if (h_count == 2) {
      h_count = 0;
      cond_o.notify_one();
    } else {
      cond_h.notify_one();
    }
  }

  void oxygen(std::function<void()> releaseOxygen) {
    std::unique_lock<std::mutex> lck(mtx_o);
    while (ready % 3 != 0) {
      cond_o.wait(lck);
    }
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    ++ready;
    cond_h.notify_one();
  }
};

#endif