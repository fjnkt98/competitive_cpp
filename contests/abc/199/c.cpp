#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, Q;
  std::string S;
  std::cin >> N >> S >> Q;
  std::vector<int64_t> T(Q);
  std::vector<int64_t> A(Q);
  std::vector<int64_t> B(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> T.at(i) >> A.at(i) >> B.at(i);
  }

  std::string s_front = S.substr(0, N);
  std::string s_back = S.substr(N, N);

  bool fliped = false;
  for (int64_t i = 0; i < Q; i++) {
    if (T.at(i) == 1) {
      if (fliped == false) {
        if (A.at(i) > N) {
          std::swap(s_back.at((A.at(i) - 1) % N), s_back.at((B.at(i) - 1) % N));
        } else {
          if (B.at(i) > N) {
            std::swap(s_front.at(A.at(i) - 1), s_back.at((B.at(i) - 1) % N));
          } else {
            std::swap(s_front.at(A.at(i) - 1), s_front.at(B.at(i) - 1));
          }
        }
      } else {
        if (A.at(i) > N) {
          std::swap(s_front.at((A.at(i) - 1) % N), s_front.at((B.at(i) - 1) % N));
        } else {
          if (B.at(i) > N) {
            std::swap(s_back.at(A.at(i) - 1), s_front.at((B.at(i) - 1) % N));
          } else {
            std::swap(s_back.at(A.at(i) - 1), s_back.at(B.at(i) - 1));
          }
        }
      }
    }
    if (T.at(i) == 2) {
      fliped = !fliped;
    }
  }

  if (fliped == false) {
    std::cout << s_front + s_back << std::endl;
  } else {
    std::cout << s_back + s_front << std::endl;
  }

  return 0;
}
