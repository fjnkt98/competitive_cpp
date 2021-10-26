#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }

  std::map<std::string, int64_t> anagram;
  for (std::string s : S) {
    std::sort(s.begin(), s.end());
    anagram[s]++;
  }

  int64_t count = 0;
  for (auto iter = anagram.begin(); iter != anagram.end(); iter++) {
    int64_t value = iter->second;
    count += (value * (value - 1)) / 2;
  }

  std::cout << count << std::endl;

  return 0;
}
