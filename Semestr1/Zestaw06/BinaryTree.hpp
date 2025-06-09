using namespace std;
#include <iostream>
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };
class BST {
private:
    Node* root;
    int size_;
    int depth_;

public:
    BST() : root(nullptr), size_(0), depth_(0){}

void insert(int x) { 
    if (root == nullptr) {
        root = new Node(x);
        size_++;
        depth_ = 1;  
        return;
    }

    Node* current = root;
    Node* parent = nullptr;
    int currentDepth = 1;  

    while (current != nullptr) {
        parent = current;
        if (x < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
        currentDepth++; 
    }

    if (x < parent->key) {
        parent->left = new Node(x);
    } else {
        parent->right = new Node(x);
    }
    
    size_++;
    if (currentDepth > depth_) {
        depth_ = currentDepth; 
    }
}


Node* search(int x){
        Node* current = root;
        while(current != nullptr && current->key != x) {
            if(x < current->key){
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return current;
}
Node* searchRecursive(int x) {
    return searchRecursivehelper(root,x);
    }

Node* searchRecursivehelper(Node* current, int x) {
    if (current == nullptr || current->key == x) {
        return current;
    }
    if (x < current->key) {
        return searchRecursivehelper(current->left, x);
    }
    return searchRecursivehelper(current->right, x);
}
int size() {
    return size_;
}
int depth() {
    return depth_;
}
int minimum() {
    if (root == nullptr) throw std::runtime_error("Tree is empty");
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->key;
}

int maximum() {
    if (root == nullptr) throw std::runtime_error("Tree is empty");
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->key;
}
void inorder() {
    inorderHelper(root);
}

void inorderHelper(Node* current) {
    if (current == nullptr) return;
    inorderHelper(current->left);
    std::cout << current->key << "\n";
    inorderHelper(current->right);
}

void preorder() {
    preorderHelper(root);
}

void preorderHelper(Node* current) {
    if (current == nullptr) return;
    std::cout << current->key << "\n";
    preorderHelper(current->left);
    preorderHelper(current->right);
}

void postorder() {
    postorderHelper(root);
}

void postorderHelper(Node* current) {
    if (current == nullptr) return;
    postorderHelper(current->left);
    postorderHelper(current->right);
    std::cout << current->key << "\n";
}
};
/* zlozonosc czasowa insert, remove, search jest:
optymisytncza O(h), h - wysokosc drzewa
pesymistyczna O(n), n - ilosc wezlow w drzewie */