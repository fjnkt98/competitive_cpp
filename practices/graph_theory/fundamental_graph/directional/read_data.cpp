#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}