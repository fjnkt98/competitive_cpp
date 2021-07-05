#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  uint64_t N, K;
  std::cin >> N >> K;

  std::vector<uint64_t> a(N);
  for (uint64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  std::vector<uint64_t> sorted_a;
  std::copy(a.begin(), a.end(), std::back_inserter(sorted_a));
  std::sort(sorted_a.begin(), sorted_a.end());

  std::map<uint64_t, uint64_t> num_of_candy;
  for (uint64_t i = 0; i < N; i++) {
    num_of_candy[a.at(i)] = K / N;
  }

  uint64_t mod = K % N;
  for (uint64_t i = 0; i < mod; i++) {
    num_of_candy[sorted_a.at(i)]++;
  }

  for (uint64_t i = 0; i < N; i++) {
    std::cout << num_of_candy[a.at(i)] << std::endl;
  }

  return 0;
}
