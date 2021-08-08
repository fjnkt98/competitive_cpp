#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cmath>

void koch_curve(
    std::pair<double, double> left,
    std::pair<double, double> right,
    int64_t recursive_depth = 6)
{
  if(recursive_depth != 0)
  {
    std::pair<double, double> s;
    std::pair<double, double> t;
    std::pair<double, double> u;

    s = std::make_pair((2 * left.first + right.first) / 3, (2 * left.second + right.second) / 3);
    t = std::make_pair((left.first + 2 * right.first) / 3, (left.second + 2 * right.second) / 3);
    u = std::make_pair((t.first - s.first) * std::cos(M_PI / 3) - (t.second - s.second) * std::sin(M_PI / 3) + s.first,
                       (t.first - s.first) * std::sin(M_PI / 3) + (t.second - s.second) * std::cos(M_PI / 3) + s.second);

    koch_curve(left, s, recursive_depth - 1);
    std::cout << std::fixed << std::setprecision(10) << s.first << " " << s.second << std::endl;
    koch_curve(s, u, recursive_depth - 1);
    std::cout << std::fixed << std::setprecision(10) << u.first << " " << u.second << std::endl;
    koch_curve(u, t, recursive_depth - 1);
    std::cout << std::fixed << std::setprecision(10) << t.first << " " << t.second << std::endl;
    koch_curve(t, right, recursive_depth - 1);
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  std::pair<double, double> left = {0.0, 0.0};
  std::pair<double, double> right = {100.0, 0.0};

  std::cout << std::fixed << std::setprecision(10) << left.first << " " << left.second << std::endl;
  koch_curve(left, right, N);
  std::cout << std::fixed << std::setprecision(10) << right.first << " " << right.second << std::endl;

  return 0;
}
