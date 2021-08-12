#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(N));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      std::cin >> A.at(i).at(j);
    }
  }
  int64_t M;
  std::cin >> M;
  std::vector<std::pair<int64_t, int64_t>> gossip(M);
  for (int64_t i = 0; i < M; i++) {
    int64_t x, y;
    std::cin >> x >> y;
    gossip.at(i) = std::make_pair(x - 1, y - 1);
  }

  std::vector<std::vector<bool>> bad_relationship(N, std::vector<bool>(N, false));
  for (int64_t i = 0; i < M; i++) {
    bad_relationship.at(gossip.at(i).first).at(gossip.at(i).second) = true;
    bad_relationship.at(gossip.at(i).second).at(gossip.at(i).first) = true;
  }


  std::vector<int64_t> p(N);
  for (int64_t i = 0; i < N; i++) {
    p.at(i) = i;
  }

  int64_t minimum_time = 1LL << 60;
  bool can_goal = false;
  do {
    bool ok = true;
    for (int64_t i = 1; i < N; i++) {
      if (bad_relationship.at(p.at(i)).at(p.at(i - 1))) {
        ok = false;
      }
    }
    int64_t sum = 0;
    if (ok) {
      can_goal = true;
      for (int64_t i = 0; i < N; i++) {
        sum += A.at(i).at(p.at(i));
      }
      minimum_time = std::min(sum, minimum_time);
    }
  } while (std::next_permutation(p.begin(), p.end()));

  if (can_goal) {
    std::cout << minimum_time << std::endl;
  } else {
    std::cout << "-1" << std::endl;
  }

  return 0;
}
