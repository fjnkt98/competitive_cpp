#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<uint64_t> enum_dividers(uint64_t N) {
  vector<uint64_t> res;
  for (uint64_t i = 1; i * i <= N; i++){
    if (N % i == 0) {
      res.push_back(i);
      if (i != (N / i)) {
        res.push_back(N / i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  uint64_t N;
  cin >> N;

  const auto &dividers = enum_dividers(N);

  uint64_t sum = 0;
  for (auto d : dividers) {
    sum += d;
  }
  sum -= N;

  if (N == sum) {
    cout << "Perfect" << endl;
  } else if (N > sum) {
    cout << "Deficient" << endl;
  } else {
    cout << "Abundant" << endl;
  }

}