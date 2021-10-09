#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<std::string> A(2 * N);
  for (int64_t i = 0; i < 2 * N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<std::vector<int64_t>> ranking(M + 1, std::vector<int64_t>(2 * N));
  for (int64_t i = 0; i < 2 * N; i++) {
    ranking.at(0).at(i) = i + 1;
  }

  std::vector<std::pair<int64_t, int64_t>> count(2 * N);
  for (int64_t i = 0; i < 2 * N; i++) {
    count.at(i) = std::make_pair(0, i);
  }

  for (int64_t i = 1; i <= M; i++) {
    for (int64_t j = 1; j <= N; j++) {
      int64_t a = ranking.at(i - 1).at(2 * j - 2) - 1;
      int64_t b = ranking.at(i - 1).at(2 * j - 1) - 1;

      if (A.at(a).at(i - 1) == 'G') {
        if (A.at(b).at(i - 1) == 'C') {
          count.at(a).first -= 1;
        } else if (A.at(b).at(i - 1) == 'P') {
          count.at(b).first -= 1;
        }
      } else if (A.at(a).at(i - 1) == 'C') {
        if (A.at(b).at(i - 1) == 'P') {
          count.at(a).first -= 1;
        } else if (A.at(b).at(i - 1) == 'G') {
          count.at(b).first -= 1;
        }
      } else if (A.at(a).at(i - 1) == 'P') {
        if (A.at(b).at(i - 1) == 'G') {
          count.at(a).first -= 1;
        } else if (A.at(b).at(i - 1) == 'C') {
          count.at(b).first -= 1;
        }
      }
    }

    
    std::vector<std::pair<int64_t, int64_t>> count_copy(2 * N);
    std::copy(count.begin(), count.end(), count_copy.begin());
    std::sort(count_copy.begin(), count_copy.end());
    for (int64_t j = 0; j < 2 * N; j++) {
      ranking.at(i).at(j) = count_copy.at(j).second + 1;
    }
    /* for (auto p : count) { */
    /*   std::cout << p.first << " "; */
    /* } */
    /* std::cout << std::endl; */
    
    /* for (auto p : ranking.at(i)) { */
    /*   std::cout << p << " "; */
    /* } */
    /* std::cout << std::endl; */
  }

  for (int64_t i = 0; i < 2 * N; i++) {
    std::cout << ranking.at(M).at(i) << std::endl;
  }

  return 0;
}
