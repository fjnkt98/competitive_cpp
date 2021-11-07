#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::map<std::string, int64_t> colors;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) < 400) {
      colors["gray"]++;
    } else if (A.at(i) < 800) {
      colors["brown"]++;
    } else if (A.at(i) < 1200) {
      colors["green"]++;
    } else if (A.at(i) < 1600) {
      colors["lightblue"]++;
    } else if (A.at(i) < 2000) {
      colors["blue"]++;
    } else if (A.at(i) < 2400) {
      colors["yellow"]++;
    } else if (A.at(i) < 2800) {
      colors["orange"]++;
    } else if (A.at(i) < 3200) {
      colors["red"]++;
    } else {
      colors["other"]++;
    }
  }

  if (colors.find("other") == colors.end()) {
    std::cout << colors.size() << " " << colors.size() << std::endl;
  } else if (colors.size() != 1) {
    std::cout << colors.size() - 1 << " " << colors.size() + colors["other"] - 1 << std::endl;
  } else {
    std::cout << 1 << " " << colors["other"] << std::endl;
  }

  return 0;
}
