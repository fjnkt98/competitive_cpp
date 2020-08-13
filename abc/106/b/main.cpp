#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<uint64_t> enum_dividers(uint64_t N) {
  vector<uint64_t> dividers;
  for (uint64_t i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      dividers.push_back(i);
      if (N / i != i) {
        dividers.push_back(N / i);
      }
    }
  }

  sort(dividers.begin(), dividers.end());
  return dividers;
}

int main() {
  uint64_t N;
  cin >> N;

  uint64_t counter = 0;
  vector<int> res;

  for (uint64_t i = 1; i <= N; i++) {
    if (i % 2 == 1) {
      const auto &dividers = enum_dividers(i);
      if (dividers.size() == 8) {
        counter++;
        res.push_back(i);
      }
    }
  }

  cout << counter << endl;
}