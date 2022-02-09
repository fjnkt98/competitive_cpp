#include <cassert>
#include <iostream>
#include <vector>

// Class implementation of binominal coefficient
class BinominalCoefficient {
 public:
  BinominalCoefficient(int64_t N, int64_t mod)
      : N_(N),
        mod_(mod),
        factorial_(N + 1, 1),
        inverse_element_(N + 1, 1),
        inverse_factorial_(N + 1, 1) {
    for (int64_t i = 2; i <= N; i++) {
      factorial_.at(i) = factorial_.at(i - 1) * i % mod_;
      inverse_element_.at(i) =
          mod_ - inverse_element_.at(mod_ % i) * (mod_ / i) % mod_;
      inverse_factorial_.at(i) =
          inverse_factorial_.at(i - 1) * inverse_element_.at(i) % mod_;
    }
  }

  int64_t nCr(int64_t n, int64_t r) {
    if (n > N_) return 0;
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;

    return factorial_.at(n) *
           (inverse_factorial_.at(r) * inverse_factorial_.at(n - r) % mod_) %
           mod_;
  }

 private:
  int64_t N_;
  int64_t mod_;
  // Memo vector of factorial
  std::vector<int64_t> factorial_;
  // Memo vector of inverse element
  std::vector<int64_t> inverse_element_;
  // Memo vector of inverse element of factorial
  std::vector<int64_t> inverse_factorial_;
};

int main() {
  int64_t N, k;
  std::cin >> N >> k;

  BinominalCoefficient bc(N + k, 1000000007);

  std::cout << bc.nCr(N + k - 1, N - 1) << std::endl;

  return 0;
}