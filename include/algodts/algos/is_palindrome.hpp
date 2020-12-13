#ifndef ISPALINDROME_HPP_
#define ISPALINDROME_HPP_

#include <string>

bool isPalindrome(std::string& s) {
  auto lower = [](char c) -> char {
    if (c > 64 && c < 91) {
      return c + 32;
    }
    return c;
  };
  auto isAscii = [](char c) -> bool {
    if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123)) {
      return true;
    }
    return false;
  };
  int front_ptr = 0;
  int back_ptr = s.length() - 1;
  while (front_ptr <= back_ptr) {
    if (!isAscii(s[front_ptr])) {
      ++front_ptr;
    } else if (!isAscii(s[back_ptr])) {
      --back_ptr;
    } else if (lower(s[front_ptr]) != lower(s[back_ptr])) {
      return false;
    } else {
      ++front_ptr;
      --back_ptr;
    }
  }
  return true;
}

#endif
