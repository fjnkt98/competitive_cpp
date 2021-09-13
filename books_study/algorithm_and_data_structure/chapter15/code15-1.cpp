/*
 * Implementation of Kruskal Method
 */

#include <iostream>
#include <vector>
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
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<std::tuple<int64_t, int64_t, int64_t>> edges(M);
  for (int64_t i = 0; i < N; i++) {
    int64_t u, v, w;
    std::cin >> u >> v >> w;
    edges.at(i) = std::make_tuple(w, u, v);
  }

  // Sort in ascending order of the weight
  std::sort(edges.begin(), edges.end());

  int64_t total_weight = 0;
  UnionFind uf(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t w = std::get<0>(edges.at(i));
    int64_t u = std::get<1>(edges.at(i));
    int64_t v = std::get<2>(edges.at(i));

    // If the addition of the edge (u, v) form a cycle,
    // don't add the edge.
    if (!uf.is_same(u, v)) {
      total_weight += w;
      uf.unite(u, v);
    }
  }

  std::cout << total_weight << std::endl;
}
