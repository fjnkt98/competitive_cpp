#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool> seen;
void dfs(const vector<vector<int>> &G, int v) {
  seen[v] = true;

  for (auto next_v : G[v]) {
    if (seen[next_v])
      continue;
    dfs(G, next_v);
  }
}

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

  seen.assign(N, false);
  dfs(G, 0);
}