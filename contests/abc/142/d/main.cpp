#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

uint64_t gcd(uint64_t x, uint64_t y) {
  return y ? gcd(y, x % y) : x;
}

vector<pair<uint64_t, uint64_t>> prime_factorize(uint64_t N) {
  vector<pair<uint64_t, uint64_t>> primes;

  for (uint64_t i = 2; i * i <= N; i++) {
    if (N % i != 0)
      continue;
    
    uint64_t ex = 0;

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
  uint64_t A, B;
  cin >> A >> B;

  uint64_t g = gcd(A, B);

  const auto &primes = prime_factorize(g);
  cout << primes.size() + 1 << endl;
}