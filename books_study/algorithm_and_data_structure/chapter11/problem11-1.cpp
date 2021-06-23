/*
 * AtCoder Beginner Contest 075 C - Bridge
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

  std::vector<int64_t> A(M);
  std::vector<int64_t> B(M);

  for (int64_t i = 0; i < M; i++) {
    std::cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < M; i++) {
    UnionFind uf(N);

    for (int64_t j = 0; j < M; j++) {
      if (i != j) {
        uf.unite(A.at(j), B.at(j));
      }
    }

    int64_t count = 0;
    for (int64_t k = 0; k < N; k++) {
      if (uf.get_root(k) == k) {
        count++;
      }
    }
    if (count > 1) {
      answer++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
