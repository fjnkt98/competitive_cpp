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

  sort(dividers.begin() ,dividers.end());
  return dividers;
}

int main() {
  uint64_t N, M;
  cin >> N >> M;

  const auto &m_divs = enum_dividers(M);

  uint64_t answer = 0;

  for (auto md : m_divs) {
    if (md <= (M / N)) {
      answer = max(answer, md);
    }
  }

  cout << answer << endl;
}