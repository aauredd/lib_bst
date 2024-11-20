#include <iostream>
using namespace std;

struct Node {
    int value, weight;
    Node* left;
    Node* right;

    Node(int d) {
        value = d;
        weight = 1;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert_recursive(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (root->value == value) {
        root->weight++;
    } else if (value < root->value) {
        root->left = insert_recursive(root->left, value);
    } else {
        root->right = insert_recursive(root->right, value);
    }
    return root;
}

Node* insert_iterative(Node* root, int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        return newNode;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (current->value == value) {
            current->weight++;
            return root;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

bool search_recursive(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == value) {
        return true;
    } else if (value < root->value) {
        return search_recursive(root->left, value);
    } else {
        return search_recursive(root->right, value);
    }
}

bool search_iterative(Node* root, int value) {
    while (root != nullptr) {
        if (root->value == value) {
            return true;
        } else if (value < root->value) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}

void in_order_traversal(Node* root) {
    if (root != nullptr) {
        in_order_traversal(root->left);
        cout << root->value << " ";
        in_order_traversal(root->right);
    }
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return max(left_height, right_height) + 1;
}

Node* delete_node(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->left = delete_node(root->left, value);
    } else if (value > root->value) {
        root->right = delete_node(root->right, value);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
    }
    return root;
}

bool is_bst(Node* root, Node* min = nullptr, Node* max = nullptr) {
    if (root == nullptr) {
        return true;
    }
    if (min != nullptr && root->value <= min->value) {
        return false;
    }
    if (max != nullptr && root->value >= max->value) {
        return false;
    }
    return is_bst(root->left, min, root) && is_bst(root->right, root, max);
}

int main() {
    Node* root = nullptr;

    root = insert_iterative(root, 50);
    root = insert_iterative(root, 30);
    root = insert_iterative(root, 20);
    root = insert_iterative(root, 40);
    root = insert_iterative(root, 70);
    root = insert_iterative(root, 60);
    root = insert_iterative(root, 80);


    return 0;
}
