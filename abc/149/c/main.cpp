#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(uint64_t N) {
  if (N == 0 || N == 1) {
    return false;
  }
  for (uint64_t i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  uint64_t X;
  cin >> X;

  for (uint64_t i = X; i <= 1000000; i++) {
    if (isPrime(i)) {
      cout << i << endl;
      return 0;
    }
  }
}