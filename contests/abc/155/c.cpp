#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::map<std::string, int64_t> count;
  for (int64_t i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;
    ++count[s];
  }

  int64_t maximum_vote = 0;
  for (auto [name, vote] : count) {
    maximum_vote = std::max(maximum_vote, vote);
  }

  std::vector<std::string> answer;
  for (auto [name, vote] : count) {
    if (vote == maximum_vote) {
      answer.push_back(name);
    }
  }

  for (auto a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}