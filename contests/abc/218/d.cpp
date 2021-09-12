#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> x(N);
  std::vector<int64_t> y(N);
  std::map<int64_t, std::set<int64_t>> vertical_point;
  for (int64_t i = 0; i < N; i++) {
    int64_t px, py;
    std::cin >> px >> py;
    x.at(i) = px;
    y.at(i) = py;
    vertical_point[px].insert(py);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i; j < N; j++) {
      if (x.at(i) != x.at(j) && y.at(i) != y.at(j)) {
        if (vertical_point[x.at(i)].find(y.at(j)) != vertical_point[x.at(i)].end()
            && vertical_point[x.at(j)].find(y.at(i)) != vertical_point[x.at(j)].end())
      {
        count++;
      }

      }
    }
  }

  std::cout << count / 2 << std::endl;

  return 0;
}
