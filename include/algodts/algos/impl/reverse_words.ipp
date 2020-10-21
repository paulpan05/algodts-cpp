#include <string>

std::string reverseWords(std::string s) {
  std::string result = "";
  int end_idx = s.length();
  bool word_started = false;
  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] != ' ' && !word_started) {
      word_started = true;
      end_idx = i;
    } else if (s[i] == ' ' && word_started) {
      word_started = false;
      for (int j = i + 1; j <= end_idx; ++j) {
        result.push_back(s[j]);
      }
      result.push_back(' ');
    }
  }
  if (word_started) {
    for (int i = 0; i <= end_idx; ++i) {
      result.push_back(s[i]);
    }
    result.push_back(' ');
  }
  if (end_idx != s.length()) {
    result.pop_back();
  }
  return result;
}