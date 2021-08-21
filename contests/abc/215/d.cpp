#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

std::vector<std::pair<int64_t, int64_t>> prime_factorize(int64_t N) {
  std::vector<std::pair<int64_t, int64_t>> primes;

  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i != 0)
      continue;

    int64_t ex = 0;

    while (N % i == 0) {
      ex++;
      N /= i;
    }

    primes.push_back({i, ex});
  }

  if (N != 1)
    primes.push_back({N, 1});

  return primes;
}

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::set<int64_t> all_primes;

  for (int64_t i = 0; i < N; i++) {
    auto primes = prime_factorize(A.at(i));
    for (auto& p : primes) {
      all_primes.insert(p.first);
    }
  }

  std::set<int64_t> candidates;
  for (int64_t i = 1; i <= M; i++) candidates.insert(i);

  std::vector<int64_t> answer;

  for (int64_t p : all_primes) {
    int64_t x = p;
    while (x <= M) {
      candidates.erase(x);
      x += p;
    }
  }

  for (int64_t c : candidates) {
    answer.push_back(c);
  }

  std::sort(answer.begin(), answer.end());
  std::cout << answer.size() << std::endl;
  for (int64_t a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}
