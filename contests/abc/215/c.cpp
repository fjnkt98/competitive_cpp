#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  std::string S;
  int64_t K;
  std::cin >> S >> K;

  std::vector<int64_t> p(S.size());
  for (size_t i = 0; i < S.size(); i++) p.at(i) = i;

  std::set<std::string> pattern;
  std::vector<std::string> dict;
  int64_t index = 1;

  do {
    std::string current_str;
    for (size_t i = 0; i < p.size(); i++) {
      current_str.push_back(S.at(p.at(i)));
    }

    if (pattern.find(current_str) == pattern.end()) {
      pattern.insert(current_str);
      dict.push_back(current_str);
      index++;
    }

  } while (std::next_permutation(p.begin(), p.end()));

  std::sort(dict.begin(), dict.end());

  std::cout << dict.at(K - 1) << std::endl;

  return 0;
}
