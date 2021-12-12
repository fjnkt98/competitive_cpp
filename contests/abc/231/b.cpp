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

  std::map<std::string, int64_t> vote;
  for (int64_t i = 0; i < N; i++) {
    vote[S.at(i)]++;
  }

  std::string answer;
  int64_t maximum = 0;
  for (auto v : vote) {
    if (maximum < v.second) {
      maximum = v.second;
      answer = v.first;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
