
#include "BinaryTree.hpp"
#include <iostream>

int main() {
    BST tree;
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        tree.insert(x);
    }
    std::cout << tree.size() << " " 
              << tree.depth() << " " 
              << tree.minimum() << " " 
              << tree.maximum() << std::endl;
    
    tree.preorder(); 
    for(int i = 1; i <= 9; i++) {
        if(tree.search(i) != nullptr) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}