#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> rated_class(N);
  for (auto& c : rated_class) {
    std::cin >> c;
  }

  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> student(Q);
  for (auto& s : student) {
    std::cin >> s;
  }

  std::sort(rated_class.begin(), rated_class.end());

  for (int64_t i = 0; i < Q; i++) {
    int64_t minimum_complain_level = 1LL << 60;
    auto iter = std::lower_bound(rated_class.begin(), rated_class.end(), student.at(i));

    if (iter == rated_class.begin()) {
      minimum_complain_level = std::min(std::abs(*iter - student.at(i)), minimum_complain_level);
    } else if (iter == rated_class.end()) {
      minimum_complain_level = std::min(std::abs(*(iter - 1) - student.at(i)), minimum_complain_level);
    } else {
      minimum_complain_level = std::min(std::abs(*iter - student.at(i)), minimum_complain_level);
      minimum_complain_level = std::min(std::abs(*(iter - 1) - student.at(i)), minimum_complain_level);
    }

    std::cout << minimum_complain_level << std::endl;
  }

  return 0;

}
