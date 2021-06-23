/*
 * Implementation of Union-Find
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
  UnionFind uf(7);

  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(5, 6);

  std::cout << uf.is_same(1, 3) << std::endl;
  std::cout << uf.is_same(2, 5) << std::endl;

  uf.unite(1, 6);
  std::cout << uf.is_same(2, 5) << std::endl;
}
