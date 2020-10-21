#ifndef REVERSEWORDSII_HPP_
#define REVERSEWORDSII_HPP_

#include <vector>

void reverseWordsII(std::vector<char>& s) {
  for (int i = 0; i < s.size() / 2; ++i) {
    char tmp = s[i];
    s[i] = s[s.size() - 1 - i];
    s[s.size() - 1 - i] = tmp;
  }
  int start_idx = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') {
      int range = i - start_idx;
      for (int j = 0; j < range / 2; ++j) {
        char tmp = s[start_idx + j];
        s[start_idx + j] = s[start_idx + range - 1 - j];
        s[start_idx + range - 1 - j] = tmp;
      }
      start_idx = i + 1;
    }
  }
  int range = s.size() - start_idx;
  for (int j = 0; j < range / 2; ++j) {
    char tmp = s[start_idx + j];
    s[start_idx + j] = s[start_idx + range - 1 - j];
    s[start_idx + range - 1 - j] = tmp;
  }
}

#endif
