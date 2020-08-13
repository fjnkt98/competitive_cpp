#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N);

  for (uint64_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  uint64_t answer = 0;
  
  sort(A.begin(), A.end());

  for (uint64_t i = 0; i < N; i++) {
    bool isDividable = true;
    for (uint64_t j = 0; j < i; j++) {
      if (i != j) {
        if (A.at(i) % A.at(j) == 0) {
          isDividable = false;
          break;
        }
      }
    }
    if (isDividable == true) {
      answer++;
    }
  }

  cout << answer << endl;
}