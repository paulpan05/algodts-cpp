#ifndef STRINGTOKENIZE_HPP_
#define STRINGTOKENIZE_HPP_

#include <string>
#include <vector>

std::vector<std::string> string_tokenize(std::string& input,
                                         std::string& token) {
  std::vector<std::string> result;
  size_t cur = 0, next = -1;
  do {
    cur = next + 1;
    next = input.find_first_of(token, cur);
    result.emplace_back(input, cur, next - cur);
  } while (next != std::string::npos);
  return result;
}

#endif