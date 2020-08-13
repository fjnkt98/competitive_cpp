#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int digit(uint64_t N) {
  int res = 0;
  while (N) {
    N /= 10;
    res++;
  }
  return res;
}

int main() {
  uint64_t N;
  cin >> N;

  int res = (1 << 29);

  for (uint64_t i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      uint64_t B = N / i;
      int F = max(digit(i), digit(B));
      res = min(res, F);
    }
  }

  cout << res << endl;
}