#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data; 
    Node* left ; 
    Node* right; 
    Node() {
        data = 0; 
        left = NULL; 
        right = NULL; 
    }
    Node(int data) {
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    }
};

int visibleNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + max( visibleNodes(root->left), 
                        visibleNodes(root->right));
    }
}


