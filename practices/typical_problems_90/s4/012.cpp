#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>

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
  int64_t H, W;
  std::cin >> H >> W;
  int64_t Q;
  std::cin >> Q;
  std::vector<std::tuple<int64_t, int64_t, int64_t, int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t;
    std::cin >> t;
    if (t == 1) {
      int64_t r, c;
      std::cin >> r >> c;
      query.at(i) = std::make_tuple(t, r - 1, c - 1, -1, -1);
    } else {
      int64_t ra, ca, rb, cb;
      std::cin >> ra >> ca >> rb >> cb;
      query.at(i) = std::make_tuple(t, ra - 1, ca - 1, rb - 1, cb - 1);
    }
  }

  std::vector<std::vector<int64_t>> grid(H, std::vector<int64_t>(W, 0));

  UnionFind uf(H * W);

  std::vector<int64_t> dr = {1, 0, -1, 0};
  std::vector<int64_t> dc = {0, 1, 0, -1};

  for (int64_t i = 0; i < Q; i++) {
    int64_t t = std::get<0>(query.at(i));
    if (t == 1) {
      int64_t r = std::get<1>(query.at(i));
      int64_t c = std::get<2>(query.at(i));
      grid.at(r).at(c) = 1;

      for (int64_t j = 0; j < 4; j++) {
        int64_t nr = r + dr.at(j);
        int64_t nc = c + dc.at(j);

        if (0 <= nr && nr < H && 0 <= nc && nc < W) {
          if (grid.at(nr).at(nc) == 1) {
            uf.unite(r * W + c, nr * W + nc);
          }
        }
      }
    } else {
      int64_t ra = std::get<1>(query.at(i));
      int64_t ca = std::get<2>(query.at(i));
      int64_t rb = std::get<3>(query.at(i));
      int64_t cb = std::get<4>(query.at(i));

      if (grid.at(ra).at(ca) != 1 || grid.at(rb).at(cb) != 1) {
        std::cout << "No" << std::endl;
        continue;
      }
      if (!uf.is_same(ra * W + ca, rb * W + cb)) {
        std::cout << "No" << std::endl;
        continue;
      }
      std::cout << "Yes" << std::endl;
    }
  }

  return 0;
}
