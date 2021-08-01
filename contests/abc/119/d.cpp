#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int64_t INF = 1LL << 60;

int main() {
  int64_t A, B, Q;
  std::cin >> A >> B >> Q;
  std::vector<int64_t> s(A);
  for (int64_t i = 0; i < A; i++) {
    std::cin >> s.at(i);
  }
  std::vector<int64_t> t(B);
  for (int64_t i = 0; i < B; i++) {
    std::cin >> t.at(i);
  }
  std::vector<int64_t> x(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> x.at(i);
  }

  for (int64_t i = 0; i < Q; i++) {

    std::vector<int64_t> closest_shrine(2);
    auto s_iter = std::lower_bound(s.begin(), s.end(), x.at(i));
    if (s_iter != s.end()) {
      closest_shrine.at(1) = *s_iter;
    } else {
      closest_shrine.at(1) = INF;
    }
    if (s_iter != s.begin()) {
      closest_shrine.at(0) = *(s_iter - 1);
    } else {
      closest_shrine.at(0) = -INF;
    }

    std::vector<int64_t> closest_temple(2);
    auto t_iter = std::lower_bound(t.begin(), t.end(), x.at(i));
    if (t_iter != t.end()) {
      closest_temple.at(1) = *t_iter;
    } else {
      closest_temple.at(1) = INF;
    }
    if (t_iter != t.begin()) {
      closest_temple.at(0) = *(t_iter - 1);
    } else {
      closest_temple.at(0) = -INF;
    }

    int64_t answer = 1LL << 60;
    for (auto s : closest_shrine) {
      for (auto t : closest_temple) {
        answer = std::min(answer, std::abs(s - x.at(i)) + std::abs(t - s));
        answer = std::min(answer, std::abs(t - x.at(i)) + std::abs(s - t));
      }
    }

    std::cout << answer << std::endl;
  }


  return 0;
}
