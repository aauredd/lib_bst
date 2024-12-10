#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int value) : data(value), weight(1), lchild(nullptr), rchild(nullptr) {}

    Node* insertR(int k) {
        if (k == data) {
            this->weight++;
        } else if (k < data) {
            if (lchild == nullptr) {
                lchild = new Node(k);
            } else {
                lchild = lchild->insertR(k);
            }
        } else {
            if (rchild == nullptr) {
                rchild = new Node(k);
            } else {
                rchild = rchild->insertR(k);
            }
        }
        return this;
    }

    Node* insertI(int k) {
        Node* current = this;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (k == current->data) {
                current->weight++;
                return this;
            } else if (k < current->data) {
                current = current->lchild;
            } else {
                current = current->rchild;
            }
        }

        Node* newNode = new Node(k);
        if (k < parent->data) {
            parent->lchild = newNode;
        } else {
            parent->rchild = newNode;
        }

        return this;
    }

    bool searchI(int k) {
        Node* current = this;
        while (current != nullptr) {
            if (current->data == k) {
                return true;
            } else if (k < current->data) {
                current = current->lchild;
            } else {
                current = current->rchild;
            }
        }
        return false;
    }

    bool searchR(int k) {
        if (this == nullptr) {
            return false;
        }
        if (this->data == k) { 
            return true;
        }
        if (k < this->data) {
            return this->lchild != nullptr && this->lchild->searchR(k);
        } else {
            return this->rchild != nullptr && this->rchild->searchR(k);
        }
    }

    void inOrder() {
        if (this->lchild != nullptr) { 
            this->lchild->inOrder();
        }
        cout << this->data << " "; 
        if (this->rchild != nullptr) {
            this->rchild->inOrder();
        }
    }

    void preOrder() {
        cout << data << " ";
        if (lchild != nullptr) {
            lchild->preOrder();
        }
        if (rchild != nullptr) {
            rchild->preOrder();
        }
    }

    void postOrder() {
        if (lchild != nullptr) {
            lchild->postOrder();
        }
        if (rchild != nullptr) {
            rchild->postOrder();
        }
        cout << data << " ";
    }

    Node* deleteNode(int k) {
        if (k < data) {
            if (lchild != nullptr) {
                lchild = lchild->deleteNode(k);
            }
        } else if (k > data) {
            if (rchild != nullptr) {
                rchild = rchild->deleteNode(k);
            }
        } else {
            if (lchild == nullptr && rchild == nullptr) {
                delete this;
                return nullptr;
            } else if (lchild == nullptr) {
                Node* temp = rchild;
                delete this;
                return temp;
            } else if (rchild == nullptr) {
                Node* temp = lchild;
                delete this;
                return temp;
            } else {
                Node* temp = rchild;
                while (temp->lchild != nullptr) {
                    temp = temp->lchild;
                }
                data = temp->data;
                rchild = rchild->deleteNode(temp->data);
            }
        }
        return this;
    }
};

int main() {
    Node* root = new Node(49);

    root->insertR(30);
    root->insertI(70);

    return 0;
}
