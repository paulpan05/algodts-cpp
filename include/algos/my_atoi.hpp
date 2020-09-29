#ifndef MYATOI_HPP_
#define MYATOI_HPP_

#include <string>
#include <limits>

using namespace std;

bool isDigit(char c) {
  if (c > 47 && c < 58) {
    return true;
  }
  return false;
}
int toDigit(char c) { return c - 48; }

int myAtoi(string str) {
  bool is_neg = false;
  bool read_started = false;
  int result = 0;
  for (int i = 0; i < str.length(); ++i) {
    if (read_started) {
      if (!isDigit(str[i])) {
        return result;
      }
      if (is_neg) {
        if (numeric_limits<int>::min() / 10 - result > 0) {
          return numeric_limits<int>::min();
        }
        result *= 10;
        int curDigit = toDigit(str[i]);
        if (numeric_limits<int>::min() - result > -curDigit) {
          return numeric_limits<int>::min();
        }
        result -= toDigit(str[i]);
      } else {
        if (numeric_limits<int>::max() / 10 - result < 0) {
          return numeric_limits<int>::max();
        }
        result *= 10;
        int curDigit = toDigit(str[i]);
        if (numeric_limits<int>::max() - result < curDigit) {
          return numeric_limits<int>::max();
        }
        result += toDigit(str[i]);
      }
    } else {
      if (isDigit(str[i])) {
        result = toDigit(str[i]);
        is_neg = false;
        read_started = true;
      } else if (str[i] == '-') {
        is_neg = true;
        read_started = true;
      } else if (str[i] == '+') {
        read_started = true;
      } else if (str[i] == ' ') {
      } else {
        return result;
      }
    }
  }
  return result;
}

#endif