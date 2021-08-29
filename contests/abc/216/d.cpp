#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> A(M);
  std::vector<std::vector<int64_t>> bucket(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t k;
    std::cin >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t a;
      std::cin >> a;
      A.at(i).push_back(a - 1);
    }

    std::reverse(A.at(i).begin(), A.at(i).end());
    bucket.at(A.at(i).back()).push_back(i);
  }

  std::queue<int64_t> que;
  for (int64_t i = 0; i < N; i++) {
    if (bucket.at(i).size() == 2) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int64_t target_color = que.front();
    que.pop();

    for (auto index : bucket.at(target_color)) {
      A.at(index).pop_back();
      if (!A.at(index).empty()) {
        bucket.at(A.at(index).back()).push_back(index);
        if (bucket.at(A.at(index).back()).size() == 2) {
          que.push(A.at(index).back());
        }
      }
    }
  }

  bool ok = true;
  for (int64_t i = 0; i < M; i++) {
    if (!A.at(i).empty()) {
      ok = false;
    }
  }

  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
