#ifndef ISPALINDROME_HPP_
#define ISPALINDROME_HPP_

#include <string>

using namespace std;

char lower(char c) {
  if (c > 64 && c < 91) {
    return c + 32;
  }
  return c;
}
bool isAscii(char c) {
  if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123)) {
    return true;
  }
  return false;
}

bool isPalindrome(string s) {
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