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

  std::map<int64_t, int64_t> sticks;
  for (int64_t i = 0; i < N; i++) {
    sticks[A.at(i)]++;
  }

  std::vector<int64_t> usable_stick_length;
  for (auto s : sticks) {
    if (s.second >= 4) {
      usable_stick_length.push_back(s.first);
      usable_stick_length.push_back(s.first);
    } else if (s.second >= 2) {
      usable_stick_length.push_back(s.first);
    }
  }

  std::sort(usable_stick_length.begin(), usable_stick_length.end(), std::greater<int64_t>{});

  if (usable_stick_length.size() < 2) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << usable_stick_length.at(0) * usable_stick_length.at(1) << std::endl;
  }

  return 0;
}
