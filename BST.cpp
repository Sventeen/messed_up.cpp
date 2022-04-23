#include<iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node() {
        this->value = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    Node* root = NULL;
    Node* insertNode(int value, Node* root) {
        if (!root)
            return new Node(value);

        if (value <= root->value) {
            root->left = insertNode(value, root->left);
        }
        else {
            root->right = insertNode(value, root->right);
        }
        return root;
    }
    void inOrder(Node* root) {
        if(!root)
            return;
        inOrder(root->left);
        std::cout << root->value << " ";
        inOrder(root->right);
    }
    void postOrder(Node* root) {
        if(!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->value << " ";
    }
    void preOrder(Node* root) {
        if(!root)
            return;
        std::cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    void insertNode(int value) {
        root = insertNode(value, root);
    }
    void inOrder() {
        inOrder(root);
    }
    void postOrder() {
        postOrder(root);
    }
    void preOrder() {
        preOrder(root);
    }
    int minElement() {
        if(!root)
            return -1;
        Node* temp = root;
        while(temp->left)
            temp = temp->left;
        return temp->value;
    }
    int maxElement() {
        if(!root)
            return -1;
        Node* temp = root;
        while(temp->right)
            temp = temp->right;
        return temp->value;
    }
};

int main() {
    BST test;
    test.insertNode(6);
    test.insertNode(9);
    test.insertNode(4);
    test.insertNode(13);
    test.insertNode(66);
    test.inOrder();
    std::cout << "\n";
    test.postOrder();
    std::cout << "\n";
    test.preOrder();
    std::cout << "\n";
    std::cout << test.minElement() << "\n";
    std::cout << test.maxElement() << "\n";
    return 0;
}