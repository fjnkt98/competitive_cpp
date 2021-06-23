/*
 * Calculate the amount of connected component by using Union Find
 */

#include <iostream>
#include <vector>
#include <utility>

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
  int64_t M;
  std::cin >> N >> M;

  UnionFind uf(N);

  for (int64_t i = 0; i < M; i++) {
    int64_t a;
    int64_t b;

    std::cin >> a >> b;
    uf.unite(a, b);
  }

  // Count root vertex
  int64_t result = 0;
  for (int64_t x = 0; x < N; x++) {
    if (uf.get_root(x) == x) {
      result++;
    }
  }

  std::cout << result << std::endl;

  return 0;
}
