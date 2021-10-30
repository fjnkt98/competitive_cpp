#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  bool ok = false;
  for (int64_t i = 0; i < N; i++) {
    if (static_cast<int64_t>(graph.at(i).size()) == N - 1) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
