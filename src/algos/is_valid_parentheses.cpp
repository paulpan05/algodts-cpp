#include "algos/is_valid_parentheses.hpp"

#include <stack>

using namespace std;

bool isValidParentheses(string s) {
  stack<char> tmp;
  for (const char c : s) {
    switch (c) {
      case ']':
        if (!tmp.empty() && tmp.top() == '[') {
          tmp.pop();
        } else {
          return false;
        }
        break;
      case '}':
        if (!tmp.empty() && tmp.top() == '{') {
          tmp.pop();
        } else {
          return false;
        }
        break;
      case ')':
        if (!tmp.empty() && tmp.top() == '(') {
          tmp.pop();
        } else {
          return false;
        }
        break;
      default:
        tmp.push(c);
    }
  }
  if (tmp.empty()) {
    return true;
  }
  return false;
}