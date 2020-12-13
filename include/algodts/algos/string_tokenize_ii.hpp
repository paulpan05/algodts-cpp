#ifndef STRINGTOKENIZEII_HPP_
#define STRINGTOKENIZEII_HPP_

#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> string_tokenize_ii(std::string& input, char token) {
  std::istringstream iss(input);
  std::string tmp;
  std::vector<std::string> result;
  while (std::getline(iss, tmp, token)) {
    result.emplace_back(tmp);
  }
  return result;
}

#endif