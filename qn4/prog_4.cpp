#include <iostream>

using namespace std;


struct d_node {
    int value;
    d_node* next_guy;
    d_node* prev_guy;
};


void put_after(d_node* target, int new_val) {
    if (target == NULL) {
        cout << "Error: Cant put after nothing!" << endl;
        return;
    }

    d_node* fresh_node = new d_node();
    fresh_node->value = new_val;
    
    
    fresh_node->next_guy = target->next_guy;
    fresh_node->prev_guy = target;

    if (target->next_guy != NULL) {
        target->next_guy->prev_guy = fresh_node;
    }
    
    target->next_guy = fresh_node;
}


void kill_node(d_node** start, d_node* target) {
    if (*start == NULL || target == NULL) return;

    
    if (*start == target) {
        *start = target->next_guy;
    }

    
    if (target->next_guy != NULL) {
        target->next_guy->prev_guy = target->prev_guy;
    }

    if (target->prev_guy != NULL) {
        target->prev_guy->next_guy = target->next_guy;
    }

    
    delete target;
}

void print_all(d_node* n) {
    while (n != NULL) {
        cout << n->value << " <-> ";
        n = n->next_guy;
    }
    cout << "NULL" << endl;
}

int main() {
    
    d_node* head_ptr = new d_node();
    head_ptr->value = 100;
    head_ptr->prev_guy = NULL;
    head_ptr->next_guy = NULL;

    cout << "Initial list: ";
    print_all(head_ptr);

    cout << "Adding 200 after 100..." << endl;
    put_after(head_ptr, 200);
    print_all(head_ptr);

    cout << "Adding 300 after 200..." << endl;
    put_after(head_ptr->next_guy, 300);
    print_all(head_ptr);

    cout << "Deleting 200 now..." << endl;
    kill_node(&head_ptr, head_ptr->next_guy);
    print_all(head_ptr);

    return 0;
}
