#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  uint64_t N;
  cin >> N;
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

  for (int i = 0; i < dividers.size(); i++) {
    cout << dividers.at(i) << " ";
  }
  cout << endl;
}