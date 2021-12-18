#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t iterative_power(int64_t a, int64_t n, int64_t p) {
 if (n == 0) return 1;
 if (n == 1) return a % p;
 if (n % 2 == 1) return (a * iterative_power(a, n - 1, p)) % p;

 int64_t t = iterative_power(a, n / 2, p);
 return (t * t) %p;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> D(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> D.at(i);
  }

  const int64_t mod = 998244353;

  int64_t maximum_distance = *std::max_element(D.begin(), D.end());
  std::vector<int64_t> count(maximum_distance + 1, 0);
  for (int64_t i = 0; i < N; i++) {
    count.at(D.at(i))++;
  }

  bool possible = true;
  if (D.at(0) != 0) possible = false;
  if (count.at(0) != 1) possible = false;

  if (possible) {
    int64_t answer = 1;
    for (int64_t i = 2; i < maximum_distance + 1; i++) {
      answer *= iterative_power(count.at(i - 1), count.at(i), mod);
      answer %= mod;
    }

    std::cout << answer << std::endl;

  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
