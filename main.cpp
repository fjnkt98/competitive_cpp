#include <cassert>
#include <iostream>
#include <vector>

class UnionFind {
 private:
  std::vector<int64_t> parent;
  std::vector<int64_t> size;
  std::vector<int64_t> rank;

 public:
  UnionFind(int64_t n) : parent(n, -1), size(n, 1), rank(n, 0) {}

  // Return the root of the tree to which x belongs
  int64_t get_root(int64_t x) {
    if (parent.at(x) == -1) {
      return x;
    } else {
      return parent.at(x) = get_root(parent.at(x));
    }
  }

  // Determine if x and y belong to the same tree
  bool is_same(int64_t x, int64_t y) { return get_root(x) == get_root(y); }

  // Merge the group to which x belongs and the group to which y belongs
  bool unite(int64_t x, int64_t y) {
    // Move x and y to their root
    x = get_root(x);
    y = get_root(y);

    // Do nothing when x and y are already in same group
    if (x == y) return false;

    // Union by rank
    if (rank.at(x) < rank.at(y)) std::swap(x, y);

    // Let y be the parent of x
    parent.at(y) = x;

    // Adjustment rank of x
    if (rank.at(x) == rank.at(y)) ++rank.at(x);
    // Compute size of x
    size.at(x) += size.at(y);

    return true;
  }

  // Size of the group to which x belongs
  int64_t get_size(int64_t x) { return size.at(get_root(x)); }
};

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  UnionFind uf(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    if (uf.is_same(a, b)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }

    uf.unite(a, b);
  }

  return 0;
}