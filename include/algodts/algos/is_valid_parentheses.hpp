#ifndef VALIDPARENTHESES_HPP_
#define VALIDPARENTHESES_HPP_

#include <stack>
#include <string>

bool isValidParentheses(std::string& s) {
  std::stack<char> tmp;
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

#endif
