#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int64_t> eratosthenes_sieve(int64_t N) {
  std::vector<int64_t> primes;
  std::vector<bool> is_prime(N + 1, true);
  is_prime.at(0) = false;
  is_prime.at(1) = false;

  for (int64_t i = 2; i <= N; i++) {
    if (is_prime.at(i)) {
      primes.push_back(i);
      for (int64_t j = 2 * i; j <= N; j += i) {
        is_prime.at(j) = false;
      }
    }
  }

  return primes;
}

bool is_prime(int64_t N) {
  if (N < 2) return false;

  bool ok = true;
  for (int64_t i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      ok = false;
    }
  }

  return ok;
}

int main() {
  int64_t Q;
  std::cin >> Q;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  int64_t max_input = 0;
  for (int64_t i = 0; i < Q; i++) {
    int64_t l, r;
    std::cin >> l >> r;
    max_input = std::max(max_input, r);
    query.at(i) = std::make_pair(l, r);
  }

  auto primes = eratosthenes_sieve(max_input);
  std::sort(primes.begin(), primes.end());

  std::vector<int64_t> like_2017(1e5 + 2);
  for (auto p : primes) {
    if (is_prime((p + 1) / 2)) {
      like_2017.at(p)++;
    }
  }
  for (int64_t i = 0; i <= 1e5; i++) {
    like_2017.at(i + 1) += like_2017.at(i);
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t l = query.at(i).first;
    int64_t r = query.at(i).second;

    std::cout << like_2017.at(r) - like_2017.at(l - 1) << std::endl;
  }

  return 0;
}
