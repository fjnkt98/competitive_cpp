#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

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
  int N;
  cin >> N;

  const int mod = 1000000007;

  vector<int> ex(N + 1, 0);

  for (int i = 2; i <= N; i++) {
    const auto &primes = prime_factorize(i);

    for (auto p : primes) {
      ex[p.first] += p.second;
    }
  }

  uint64_t answer = 1;
  for (int i = 2; i <= N; i++) {
    answer *= (ex[i] + 1);
    answer %= mod;
  }

  cout << answer << endl;
}