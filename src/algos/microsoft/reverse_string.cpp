#include "algos/microsoft/reverse_string.hpp"

using namespace std;

void reverseString(vector<char>& s) {
  for (int i = 0; i < s.size() / 2; ++i) {
    char tmp = s[i];
    s[i] = s[s.size() - 1 - i];
    s[s.size() - 1 - i] = tmp;
  }
}