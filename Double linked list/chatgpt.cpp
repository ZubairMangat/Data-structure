#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void deleteNode(Node*& head, Node* del) {
    // Case 1: Empty list or invalid node
    if (head == nullptr || del == nullptr) {
        return;
    }

    // Case 2: Deleting the head node
    if (head == del) {
        head = del->next;
    }

    // Case 3: If the node to be deleted is not the last node
    if (del->next != nullptr) {
        del->next->prev = del->prev;
    }

    // Case 4: If the node to be deleted is not the first node
    if (del->prev != nullptr) {
        del->prev->next = del->next;
    }

    // Free memory for the deleted node
    delete del;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Create a doubly linked list: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    cout << "Original list: ";
    printList(head);

    // Delete a node (for example, the node with value 20)
    deleteNode(head, head->next);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
