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


    return 0;
}

