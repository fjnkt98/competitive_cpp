#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

class EratosthenesSieve {
 public:
  int64_t Number_;
  std::vector<bool> is_prime_;
  std::vector<int64_t> primes_;
  std::vector<int64_t> minimum_factor_;

  EratosthenesSieve(int64_t N)
      : Number_(N),
        is_prime_(N + 1, true),
        primes_(0),
        minimum_factor_(N + 1, -1) {
    is_prime_.at(1) = false;
    minimum_factor_.at(1) = 1;

    for (int64_t p = 2; p <= N; p++) {
      if (!is_prime_.at(p)) continue;

      primes_.push_back(p);
      minimum_factor_.at(p) = p;

      for (int64_t q = p * 2; q <= N; q += p) {
        is_prime_.at(q) = false;

        if (minimum_factor_.at(q) == -1) {
          minimum_factor_.at(q) = p;
        }
      }
    }
  }

  std::vector<std::pair<int64_t, int64_t>> factorize(int64_t N) {
    if (N > Number_) return {};
    std::vector<std::pair<int64_t, int64_t>> result;
    while (N > 1) {
      int64_t p = minimum_factor_.at(N);
      int64_t exp = 0;

      while (minimum_factor_.at(N) == p) {
        N /= p;
        exp++;
      }
      result.push_back(std::make_pair(p, exp));
    }

    return result;
  }

  std::vector<int64_t> dividers(int64_t N) {
    if (N > Number_) return {};
    std::vector<int64_t> result = {1};

    auto primes = factorize(N);

    for (auto p : primes) {
      int64_t size = static_cast<int64_t>(result.size());
      for (int64_t i = 0; i < size; i++) {
        int64_t v = 1;
        for (int64_t j = 0; j < p.second; j++) {
          v *= p.first;
          result.push_back(result.at(i) * v);
        }
      }
    }

    std::sort(result.begin(), result.end());
    return result;
  }

  std::vector<int64_t> primes(void) { return primes_; }

  std::vector<bool> is_prime(void) { return is_prime_; }
};

int main() {
  int64_t N;
  std::cin >> N;

  EratosthenesSieve es(N);

  int64_t answer = 0;
  for (int64_t i = 1; i <= N; i++) {
    auto divisors = es.dividers(i);
    answer += i * divisors.size();
  }

  std::cout << answer << std::endl;

  return 0;
}