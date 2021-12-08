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

  bool all_same = true;
  for (int64_t i = 1; i < N; i++) {
    if (A.at(i - 1) != A.at(i)) {
      all_same = false;
    }
  }

  if (all_same) {
    std::cout << N / 2 << std::endl;
    return 0;
  }

  std::map<int64_t, int64_t> odd_count;
  std::map<int64_t, int64_t> even_count;

  for (int64_t i = 0; i < N; i++) {
    if (i % 2 == 0) {
      even_count[A.at(i)]++;
    } else {
      odd_count[A.at(i)]++;
    }
  }

  std::vector<std::pair<int64_t, int64_t>> odd_freq;
  std::vector<std::pair<int64_t, int64_t>> even_freq;
  for (auto o : odd_count) {
    odd_freq.push_back(std::make_pair(o.second, o.first));
  }
  for (auto e : even_count) {
    even_freq.push_back(std::make_pair(e.second, e.first));
  }

  std::sort(odd_freq.begin(), odd_freq.end(), std::greater<std::pair<int64_t, int64_t>>{});
  std::sort(even_freq.begin(), even_freq.end(), std::greater<std::pair<int64_t, int64_t>>{});

  int64_t answer = 0;
  if (odd_freq.at(0).second != even_freq.at(0).second) {
    answer =  N - odd_freq.at(0).first - even_freq.at(0).first;
  } else {
    answer = std::min(N - odd_freq.at(0).first - even_freq.at(1).first,
                      N - odd_freq.at(1).first - even_freq.at(0).first);
  }

  std::cout << answer << std::endl;

  return 0;
}
