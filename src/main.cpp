// Copyright 2021 NNTU-CS
#include <iostream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;
  makeTree(tree, "src/war_peace.txt");
  std::cout << "Tree depth: " << tree.depth() << std::endl;
  std::cout << "Search 'the': " << tree.search("the") << std::endl;
  std::cout << "Search 'war': " << tree.search("war") << std::endl;
  std::cout << "Search 'peace': " << tree.search("peace") << std::endl;
  std::cout << "\nFrequency analysis (top words):" << std::endl;
  printFreq(tree);
  return 0;
}
