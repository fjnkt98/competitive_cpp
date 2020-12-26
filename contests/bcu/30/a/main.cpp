#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int M;
  cin >> M;
  vector<int> B(M);
  for (int j = 0; j < M; j++) {
    cin >> B.at(j);
  }

  int prod = 1;
  for (auto a : A) {
    prod *= a;
  }

  for (int j = 0; j < M; j++) {
    if (prod % B.at(j) != 0) {
      cout << "No" << endl;
      return 0;
    } else {
      prod /= B.at(j);
    }
  }

  cout << "Yes" << endl;
}