#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::map<int64_t, int64_t> count;
  std::map<int64_t, int64_t> combination;
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    count[A.at(i)]++;
  }

  for (auto iter = count.begin(); iter != count.end(); iter++) {
    combination[iter->first] = iter->second * (iter->second - 1) / 2;
  }

  int64_t sum = 0;
  for (auto c : combination) {
    sum += c.second;
  }

  for (int64_t i = 0; i < N; i++) {
    int64_t banned_count = count[A.at(i)] - 1;
    std::cout << sum - combination[A.at(i)] + (banned_count * (banned_count - 1)) / 2 << std::endl;
  }


  return 0;
}
