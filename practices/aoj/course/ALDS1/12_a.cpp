#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

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
  int64_t N;
  std::cin >> N;
  /* std::vector<std::vector<int64_t>> graph(N); */
  std::vector<std::tuple<int64_t, int64_t, int64_t>> edges;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      int64_t w;
      std::cin >> w;
      if (w != -1) {
        edges.push_back(std::make_tuple(w, i, j));
      }
    }
  }

  std::sort(edges.begin(), edges.end());

  UnionFind uf(N);
  int64_t total_weight = 0;
  for (auto e : edges) {
    int64_t weight = std::get<0>(e);
    int64_t u = std::get<1>(e);
    int64_t v = std::get<2>(e);

    if (!uf.is_same(u, v)) {
      uf.unite(u, v);
      total_weight += weight;
    }
  }

  std::cout << total_weight << std::endl;

  return 0;
}
