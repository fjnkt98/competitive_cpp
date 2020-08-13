#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> G(N);

  for (int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    G[from].push_back(make_pair(to, weight));
  }
}