#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;
  std::string S;
  std::cin >> S;

  int64_t capacity = 0;
  int64_t foreigner = 0;

  for (size_t i = 0; i < S.size(); i++) {
    if (S.at(i) == 'c') {
      std::cout << "No" << std::endl;
    } else if (S.at(i) == 'a') {
      if (capacity < A + B) {
        std::cout << "Yes" << std::endl;
        capacity++;
      } else {
        std::cout << "No" << std::endl;
      }
    } else if (S.at(i) == 'b') {
      if (capacity < A + B && B > foreigner) {
        std::cout << "Yes" << std::endl;
        capacity++;
        foreigner++;
      } else {
        std::cout << "No" << std::endl;
      }
    }
  }

  return 0;
}
