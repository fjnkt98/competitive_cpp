#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  // Copied array for referance
  std::vector<int64_t> sorted_a;
  std::copy(a.begin(), a.end(), std::back_inserter(sorted_a));

  // Array to store answers
  std::vector<int64_t> answer(N, 0);

  std::sort(sorted_a.begin(), sorted_a.end());
  for (int64_t i = 0; i < N; i++) {
    answer.at(i) = static_cast<int64_t>(
        std::lower_bound(
          sorted_a.begin(), sorted_a.end(), a.at(i)
          ) - sorted_a.begin()
        );
  }

  for (auto item : answer) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
