#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class UnionFind {
 private:
   std::vector<int64_t> parent;
   std::vector<int64_t> size;

  public:
   UnionFind(int64_t n)
   : parent(n, -1), size(n, 1)
   {
   }

   // Return the root of the tree to which x belongs
   int64_t get_root(int64_t x) {
     if (parent.at(x) == -1) {
       return x;
     } else {
       return parent.at(x) = this->get_root(parent.at(x));
     }
   }

   // Determine if x and y belong to the same tree
   bool is_same(int64_t x, int64_t y) {
     return this->get_root(x) == this->get_root(y);
   }

   // Merge the group to which x belongs and the group to which y belongs
   bool unite(int64_t x, int64_t y) {
     // Move x and y to their root
     x = this->get_root(x);
     y = this->get_root(y);

     // Do nothing when x and y are already in same group
     if (x == y) {
       return false;
     }

     // union by size
     if (size.at(x) < size.at(y)) {
       std::swap(x, y);
     }

     parent.at(y) = x;
     size.at(x) += size.at(y);

     return true;
   }

   // Size of the group to which x belongs
   int64_t get_size(int64_t x) {
     return size.at(this->get_root(x));
   }
};

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    graph.at(a - 1).push_back(b - 1);
    /* graph.at(b - 1).push_back(a - 1); */
  }

  std::vector<int64_t> answer = {0};
  UnionFind uf(N);

  int64_t connected_component = 0;
  for (int64_t i = N - 1; i > 0; i--) {
    connected_component++;

    for (int64_t j : graph.at(i)) {
      if (!uf.is_same(i, j)) {
        uf.unite(i, j);
        connected_component--;
      }
    }

    answer.push_back(connected_component);
  }

  std::reverse(answer.begin(), answer.end());

  for (int64_t i = 0; i < N; i++) {
    std::cout << answer.at(i) << std::endl;
  }

  return 0;
}
