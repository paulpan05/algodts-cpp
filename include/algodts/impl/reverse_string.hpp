#ifndef REVERSESTRING_HPP_
#define REVERSESTRING_HPP_

#include <algorithm>
#include <vector>

using namespace std;

inline void reverseString(vector<char>& s) {
  for (int i = 0; i < s.size() / 2; ++i) {
    swap(s[i], s[s.size() - i - 1]);
  }
}

#endif