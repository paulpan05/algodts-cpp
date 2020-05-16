#include "algos/my_atoi.hpp"

#include <climits>

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
        if (INT_MIN / 10 - result > 0) {
          return INT_MIN;
        }
        result *= 10;
        int curDigit = toDigit(str[i]);
        if (INT_MIN - result > -curDigit) {
          return INT_MIN;
        }
        result -= toDigit(str[i]);
      } else {
        if (INT_MAX / 10 - result < 0) {
          return INT_MAX;
        }
        result *= 10;
        int curDigit = toDigit(str[i]);
        if (INT_MAX - result < curDigit) {
          return INT_MAX;
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