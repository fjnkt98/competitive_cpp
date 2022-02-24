#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t current_number = 0;
  int64_t current_chain = 1;
  std::vector<int64_t> pipe;
  for (int64_t i = 0; i < N; i++) {
    pipe.push_back(A.at(i));

    if (A.at(i) == current_number) {
      ++current_chain;

      if (current_chain == current_number) {
        while (current_chain > 0) {
          pipe.pop_back();
          --current_chain;
        }

        current_chain = 0;
        current_number = pipe.back();
        for (int64_t i = static_cast<int64_t>(pipe.size()) - 1; i >= 0; i--) {
          if (pipe.at(i) == current_number) {
            ++current_chain;
          } else {
            break;
          }
        }
      }
    } else {
      current_number = A.at(i);
      current_chain = 1;
    }

    std::cout << pipe.size() << std::endl;
  }

  return 0;
}
