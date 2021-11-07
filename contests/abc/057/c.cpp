#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int64_t> enumerate_dividers(int64_t N) {
  std::vector<int64_t> dividers;

  for (int64_t i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      dividers.push_back(i);
    }
  }

  std::sort(dividers.begin(), dividers.end());
  return dividers;
}

int64_t F(int64_t A, int64_t B) {
  std::string a = std::to_string(A);
  std::string b = std::to_string(B);

  return std::max(a.size(), b.size());
}

int main() {
  int64_t N;
  std::cin >> N;

  int64_t answer = 1LL << 60;
  auto dividers = enumerate_dividers(N);
  for (int64_t A : dividers) {
    int64_t B = N / A;

    answer = std::min(answer, F(A, B));
  }

  std::cout << answer << std::endl;

  return 0;
}
