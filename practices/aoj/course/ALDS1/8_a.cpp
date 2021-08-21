#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

class BinarySearchTreeElement {
  public:
    int64_t key;
    std::shared_ptr<BinarySearchTreeElement> parent;
    std::shared_ptr<BinarySearchTreeElement> left;
    std::shared_ptr<BinarySearchTreeElement> right;

    BinarySearchTreeElement (int64_t key,
      std::shared_ptr<BinarySearchTreeElement> parent = nullptr,
      std::shared_ptr<BinarySearchTreeElement> left = nullptr,
      std::shared_ptr<BinarySearchTreeElement> right = nullptr)
      : key(key)
    {
      this->parent = std::move(parent);
      this->left = std::move(left);
      this->right = std::move(right);
    }
};

class BinarySearchTree {
  public:
    std::shared_ptr<BinarySearchTreeElement> root;

    BinarySearchTree() {
      this->root = nullptr;
    }
    BinarySearchTree (int64_t key) {
      this->root = std::make_shared<BinarySearchTreeElement>(key);
    }

    void insert(int64_t key) {
      std::shared_ptr<BinarySearchTreeElement> x = this->root;
      std::shared_ptr<BinarySearchTreeElement> y = nullptr;
      std::shared_ptr<BinarySearchTreeElement> z = std::make_shared<BinarySearchTreeElement>(key);

      while (x != nullptr) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
      }

      z->parent = y;
      if (y == nullptr) {
        this->root = z;
      } else {
        if (z->key < y->key) {
          y->left = z;
        } else {
          y->right = z;
        }
      }
    }
};

void preorder_explore(std::vector<int64_t>& order,
    std::shared_ptr<BinarySearchTreeElement> node)
{
  if (node == nullptr) return;
  order.push_back(node->key);

  preorder_explore(order, node->left);
  preorder_explore(order, node->right);
}

void inorder_explore(std::vector<int64_t>& order,
    std::shared_ptr<BinarySearchTreeElement> node)
{
  if (node == nullptr) return;
  inorder_explore(order, node->left);
  order.push_back(node->key);
  inorder_explore(order, node->right);
}

int main() {
  int64_t N;
  std::cin >> N;

  BinarySearchTree tree;

  for (int64_t i = 0; i < N; i++) {
    std::string command;
    std::cin >> command;
    if (command == "insert") {
      int64_t value;
      std::cin >> value;

      tree.insert(value);
    } else {
      std::vector<int64_t> inorder;
      inorder_explore(inorder, tree.root);

      for (size_t j = 0; j < inorder.size(); j++) {
        std::cout << " " << inorder.at(j);
      }
      std::cout << std::endl;

      std::vector<int64_t> preorder;
      preorder_explore(preorder, tree.root);

      for (size_t j = 0; j < preorder.size(); j++) {
        std::cout << " " << preorder.at(j);
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
