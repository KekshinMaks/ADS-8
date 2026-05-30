// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;
    Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
  };
  Node* root;
  int depthRec(Node* node) const {
    if (!node) return 0;
    int leftDepth = depthRec(node->left);
    int rightDepth = depthRec(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
  }
  Node* insertRec(Node* node, const T& key) {
    if (!node) return new Node(key);
    if (key < node->key) {
      node->left = insertRec(node->left, key);
    } else if (key > node->key) {
      node->right = insertRec(node->right, key);
    } else {
      node->count++;
    }
    return node;
  }
  Node* searchRec(Node* node, const T& key) const {
    if (!node || node->key == key) return node;
    if (key < node->key) return searchRec(node->left, key);
    return searchRec(node->right, key);
  }
  void inorderRec(Node* node, void (*visit)(const T&, int)) const {
    if (node) {
      inorderRec(node->left, visit);
      visit(node->key, node->count);
      inorderRec(node->right, visit);
    }
  }
  void clearRec(Node* node) {
    if (node) {
      clearRec(node->left);
      clearRec(node->right);
      delete node;
    }
  }
  void collectRec(Node* node, std::vector<std::pair<T, int>>& vec) const {
    if (node) {
      collectRec(node->left, vec);
      vec.push_back({node->key, node->count});
      collectRec(node->right, vec);
    }
  }
 public:
  BST() : root(nullptr) {}
  ~BST() { clearRec(root); }
  void insert(const T& key) { root = insertRec(root, key); }
  int search(const T& key) const {
    Node* result = searchRec(root, key);
    return result ? result->count : 0;
  }
  int depth() const { return depthRec(root); }
  void inorder(void (*visit)(const T&, int)) const {
    inorderRec(root, visit);
  }
  std::vector<std::pair<T, int>> toVector() const {
    std::vector<std::pair<T, int>> result;
    collectRec(root, result);
    return result;
  }
};

#endif  // INCLUDE_BST_H_
