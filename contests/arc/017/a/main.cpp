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
  uint64_t N;
  cin >> N;

  if (isPrime(N)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}