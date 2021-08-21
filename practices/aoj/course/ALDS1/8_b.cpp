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

/*
 * Implement of Binary Search Tree
 * This class holds a single binary search tree, and handles the insertion, search, and deletion operations.
 * In fact, this class holds only the root of the tree.
 */
class BinarySearchTree {
  public:
    std::shared_ptr<BinarySearchTreeElement> root;

    BinarySearchTree() {
      this->root = nullptr;
    }
    BinarySearchTree (int64_t key) {
      this->root = std::make_shared<BinarySearchTreeElement>(key);
    }

    /* Insert the key into the tree. */
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

    /* Determine if the key is in the tree.
     * The function returns a shared-pointer to the node with the key.
     * If the key doesn't exist in the tree, if returns nullptr.
     */
    std::shared_ptr<BinarySearchTreeElement> find(int64_t key) {
      std::shared_ptr<BinarySearchTreeElement> x = this->root;
      while (x != nullptr && x->key != key) {
        if (key < x->key)x = x->left;
        else x = x->right;
      }

      return x;
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
    } else if (command == "find") {
      int64_t value;
      std::cin >> value;

      if (tree.find(value) == nullptr) {
        std::cout << "no" << std::endl;
      } else {
        std::cout << "yes" << std::endl;
      }
    } else if (command == "print") {
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
