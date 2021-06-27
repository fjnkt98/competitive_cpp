#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::pair<int64_t, int64_t>> S(N);
  std::vector<std::pair<int64_t, int64_t>> T(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i).first >> S.at(i).second;
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> T.at(i).first >> T.at(i).second;
  }

  // Calculate relative position from the center of mass for S
  std::pair<int64_t, int64_t> center_of_S = std::make_pair(0, 0);
  for (int64_t i = 0; i < N; i++) {
    center_of_S.first += S.at(i).first;
    center_of_S.second += S.at(i).second;

    S.at(i).first *= N;
    S.at(i).second *= N;
  }

  for (int64_t i = 0; i < N; i++) {
    S.at(i).first -= center_of_S.first;
    S.at(i).second -= center_of_S.second;
  }

  // Calculate relative position from the center of mass for T
  std::pair<int64_t, int64_t> center_of_T = std::make_pair(0, 0);
  for (int64_t i = 0; i < N; i++) {
    center_of_T.first += T.at(i).first;
    center_of_T.second += T.at(i).second;

    T.at(i).first *= N;
    T.at(i).second *= N;
  }
  for (int64_t i = 0; i < N; i++) {
    T.at(i).first -= center_of_T.first;
    T.at(i).second -= center_of_T.second;
  }

  // Avoid to atan2 error
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i).first != 0 || S.at(i).second != 0) {
      std::swap(S.at(i).first, S.at(0).first);
      std::swap(S.at(i).second, S.at(0).second);
    }
  }

  const double epsilon = 1e-6;
  bool ok = false;
  for (int64_t i = 0; i < N; i++) {
    double angle = std::atan2(T.at(i).second, T.at(i).first) - std::atan2(S.at(0).second, S.at(0).first);

    bool flag1 = true;
    for (int64_t j = 0; j < N; j++) {
      double x = S.at(j).first * std::cos(angle) - S.at(j).second * std::sin(angle);
      double y = S.at(j).first * std::sin(angle) + S.at(j).second * std::cos(angle);

      bool flag2 = false;

      for (int64_t k = 0; k < N; k++) {
        if (std::abs(x - T.at(k).first) <= epsilon && std::abs(y - T.at(k).second) <= epsilon) {
          flag2 = true;
        }
      }
      flag1 &= flag2;
    }

    if (flag1) {
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
