#include <iostream>
using namespace std;

class Node {
private:
    int data;         
    int weight;       
    Node* lchild;     
    Node* rchild;     

public:

    
    friend ostream& operator<<(ostream &os, const Node &node){
    os << Node.data <<endl;
    return os;
        };
    }
    friend istream& operator>>(istream& is, Node*& node) {
        int value;
        is>>value;
    Node->insertR(value);
        return is;
    }
    }
    Node(int value) : data(value), weight(1), lchild(nullptr), rchild(nullptr) {}

    Node* insertR(int k) {
        if (k == data) {
            weight++;
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
    if (data == k) {
        return true;
    } 
    if (k < data) {
        if (lchild != nullptr) {
            return lchild->searchR(k);
        } else {
            return false;
        }
    } else {
        if (rchild != nullptr) {
            return rchild->searchR(k);
        } else {
            return false;
        }
    }
}


    void inOrder() {
        if (lchild != nullptr) {
            lchild->inOrder();
        }
        cout << data << " ";
        if (rchild != nullptr) {
            rchild->inOrder();
        }
    }

    int getData() const { return data; }
};

int main() {
    Node* root = new Node(50);

    root = root->insertR(30);
    root = root->insertR(20);
    root = root->insertR(40);
    root = root->insertR(70);
    root = root->insertR(60);
    root = root->insertR(80);

cin>>
    return 0;
}
