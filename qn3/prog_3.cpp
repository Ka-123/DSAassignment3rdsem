#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* nextnode;
};

void add_item(Node*& headptr, int data) {
    Node* temp = new Node();
    temp->val = data;
    temp->nextnode = NULL;
    
    if (headptr == NULL) {
        headptr = temp;
    } else {
        Node* curr = headptr;
        while (curr->nextnode != NULL) {
            curr = curr->nextnode;
        }
        curr->nextnode = temp;
    }
}

void print_backwards(Node* n) {
    if (n == NULL) {
        return;
    }
    print_backwards(n->nextnode);
    cout << n->val << " ";
}

int main() {
    Node* mylist = NULL;
    
    add_item(mylist, 10);
    add_item(mylist, 20);
    add_item(mylist, 30);
    add_item(mylist, 40);
    add_item(mylist, 50);

    cout << "original list was: 10 20 30 40 50" << endl;
    cout << "printing it in reverse now: ";
    print_backwards(mylist);
    cout << endl;

    return 0;
}
