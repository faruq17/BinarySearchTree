
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;
    
    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }
    
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val) return node;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }
    
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;
        if (key < root->data) root->left = deleteNode(root->left, key);
        else if (key > root->data) root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    
    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    
    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
    
public:
    BST() { root = nullptr; }
    
    void insert(int val) { root = insert(root, val); }
    
    Node* search(int val) { return search(root, val); }
    
    void deleteNode(int val) { root = deleteNode(root, val); }
    
    void inorder() { inorder(root); cout << endl; }
    
    void preorder() { preorder(root); cout << endl; }
    
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    
    cout << "Inorder traversal: ";
    tree.inorder();
    
    cout << "Preorder traversal: ";
    tree.preorder();
    
    cout << "Postorder traversal: ";
    tree.postorder();
    
    cout << "Search 40: " << (tree.search(40) != nullptr ? "Found" : "Not Found") << endl;
    cout << "Delete 20\n";
    tree.deleteNode(20);
    cout << "Inorder traversal: ";
    tree.inorder();
    
    return 0;
}
