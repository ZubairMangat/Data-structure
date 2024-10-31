// #include <iostream>
// using namespace std;
// struct node
// {
//     /* data */
//     int data;
//     node* next;
//     node* previous;

// };
// node * head =nullptr;
// void InsertionAtBegining(int value){
//     node *p =new node;
//     p->data=value;
//     p->next=nullptr;
//     p->previous=nullptr;
//     if(head == nullptr){
//         head=p;
//     }
//     else{
//         p->next=head;//head->previous=p;
//         head->previous=p;
//         head=p;
//     }

// }
// void InsertAtEnd(int value){
//     node* p=new node;

//     if (head ==nullptr){
//         head =p;
//     }
//     else
//     {
//         node *currentNode=head;
//         while(currentNode!=0){
//             currentNode=currentNode->next;
//         }
//         currentNode->next=p;
//         p->previous=currentNode;
//         p->next=nullptr;

//     }

// }
// bool search(int value){
//     node*th =head;
//     while(th!=nullptr){
        
//         if (th->data==value){
//             cout<<"Found!!!";
//             return true;
//         }
//         th=th->next;
//     }
//     return false;
// }
// void print(){
//     node* th =head;
//     while(th!=nullptr){
//         cout<<th->data;
//         th=th->next;
//     }
// }

// void InsertInBetween(int value,int nodeAfter){
//     node* Newnode=new node;
//     Newnode->data=value;
//     Newnode->next=nullptr;
//     Newnode->previous=nullptr;
//     node* CurrentNode=head;

//     if(head==nullptr){
//         head=Newnode;       

//     }
//     else
//     {
//         while(CurrentNode->data!=nodeAfter){
//             CurrentNode=CurrentNode->next;
//         }
//         CurrentNode->next->previous=Newnode;
//         Newnode->next=CurrentNode->next;
//         CurrentNode->next=Newnode;
//         Newnode->previous=CurrentNode;
//     }
// }
// void deletion(int value){
//     if(head==nullptr){
//         cout<<"Nothing to delete List is empty!!!";
//     }
//     if (head->data==value){
//         node* current= head;
//         head=head->next;
//         head->previous=nullptr;
//         delete current;
//     }
//     node* current= head;

//     while(current!=nullptr &&current->data==value){
//         current=current->next;
//     }
//     if (current==nullptr){
//         cout<<"The value is not in the list!!";

//     }
//     if(current!=nullptr){
//         current->next->previous=current->previous;
//         current->previous->next=current->next;
//         delete current;
//     }
// }
// int main (){
//     //p->data=12
    


// }
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* previous;
};

node* head = nullptr;

// Mistake 1: `InsertionAtBegining` should be `InsertionAtBeginning` to match standard spelling
void InsertionAtBeginning(int value) {
    node* p = new node;
    p->data = value;
    p->next = head;
    p->previous = nullptr;

    if (head != nullptr) {
        head->previous = p;
    }
    head = p;
}

void InsertAtEnd(int value) {
    node* p = new node;
    p->data = value;
    p->next = nullptr;
    p->previous = nullptr;

    // Mistake 2: Forgot to initialize the `data`, `next`, and `previous` pointers of `p`.
    // Corrected by initializing them here.

    if (head == nullptr) {
        head = p;
    } else {
        node* currentNode = head;

        // Mistake 3: The condition in the loop was `while(currentNode != 0)` instead of `while(currentNode->next != nullptr)`
        // Using `currentNode != 0` will lead to an infinite loop because `currentNode->next` should be checked to reach the end.
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }

        currentNode->next = p;
        p->previous = currentNode;
        // Mistake 4: `p->next` was not set to `nullptr`, which could lead to an incorrect list structure.
        // This is corrected by initializing `p->next` to `nullptr` at the start.
    }
}

bool search(int value) {
    node* th = head;
    while (th != nullptr) {
        if (th->data == value) {
            cout << "Found!" << endl;
            return true;
        }
        th = th->next;
    }
    cout << "Not Found!" << endl;
    return false;
}

void print() {
    node* th = head;
    while (th != nullptr) {
        cout << th->data << " ";
        th = th->next;
    }
    cout << endl;
}

void InsertInBetween(int value, int nodeAfter) {
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    node* currentNode = head;

    if (head == nullptr) {
        head = newNode;
    } else {
        // Mistake 5: No check to ensure that `nodeAfter` exists in the list.
        // The following while loop will throw an error if `nodeAfter` is not found.
        while (currentNode != nullptr && currentNode->data != nodeAfter) {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr) {
            cout << "Node with value " << nodeAfter << " not found!" << endl;
            delete newNode;
            return;
        }

        newNode->next = currentNode->next;
        if (currentNode->next != nullptr) {
            currentNode->next->previous = newNode;
        }
        currentNode->next = newNode;
        newNode->previous = currentNode;
    }
}

// void deletion(int value) {
//     if (head == nullptr) {
//         cout << "Nothing to delete. List is empty!" << endl;
//         return;
//     }

//     // Mistake 6: The `if` statement to check if `head` contains `value` didn't handle cases where `head` might be the only node.
//     // This can cause an error when setting `head->previous = nullptr`.
//     if (head->data == value) {
//         node* current = head;
//         head = head->next;
//         if (head != nullptr) {
//             head->previous = nullptr;
//         }
//         delete current;
//         cout << "Node with value " << value << " deleted from the head." << endl;
//         return;
//     }

//     // Mistake 7: The loop condition `while(current != nullptr && current->data == value)` should be `!= value`
//     // `while(current != nullptr && current->data != value)` is correct for finding the matching node.
//     node* current = head;
//     while (current != nullptr && current->data != value) {
//         current = current->next;
//     }

//     // Mistake 8: No check if `current` is nullptr after the loop, which can cause errors if `value` is not found.
//     if (current == nullptr) {
//         cout << "The value " << value << " is not in the list!" << endl;
//         return;
//     }

//     // Update pointers to bypass `current`
//     if (current->next != nullptr) {
//         current->next->previous = current->previous;
//     }

//     if (current->previous != nullptr) {
//         current->previous->next = current->next;
//     }

//     delete current;
//     cout << "Node with value " << value << " deleted from the list." << endl;
// }
// void deletion(int value) {
//     if (head == nullptr) {
//         cout << "Nothing to delete. List is empty!" << endl;
//         return;
//     }

//     // Special case: if the node to delete is the head
//     if (head->data == value) {
//         node* current = head;
//         head = head->next;
//         if (head != nullptr) {
//             head->previous = nullptr;
//         }
//         delete current;
//         cout << "Node with value " << value << " deleted from the head." << endl;
//         return;
//     }

//     // Traverse to find the node with the matching value
//     node* current = head;
//     while (current != nullptr && current->data != value) {
//         current = current->next;
//     }

//     // If `value` is not found in the list
//     if (current == nullptr) {
//         cout << "The value " << value << " is not in the list!" << endl;
//         return;
//     }

//     // Directly update pointers without checks
//     current->next->previous = current->previous;
//     current->previous->next = current->next;

//     delete current;
//     cout << "Node with value " << value << " deleted from the list." << endl;
// }

void deletion(int value) {
    if (head == nullptr) {
        cout << "Nothing to delete. List is empty!" << endl;
        return;
    }

    // Case 1: If the node to delete is the head (first node)
    if (head->data == value) {
        node* current = head;
        head = head->next;  // Move head to the next node
        if (head != nullptr) {
            head->previous = nullptr;  // Set previous of new head to nullptr
        }
        delete current;
        cout << "Node with value " << value << " deleted from the head." << endl;
    }
    else {
        // Traverse to find the node with the matching value
        node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // Case 2: If the value is not found
        if (current == nullptr) {
            cout << "The value " << value << " is not in the list!" << endl;
        }
        // Case 3: If `current` is the last node (end node)
        else if (current->next == nullptr) {
            current->previous->next = nullptr;  // Set the next of the previous node to nullptr
            delete current;
            cout << "Node with value " << value << " deleted from the end." << endl;
        }
        // Case 4: If `current` is a middle node
        else {
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current;
            cout << "Node with value " << value << " deleted from the middle." << endl;
        }
    }
}

int main() {
    InsertionAtBeginning(10);
    InsertionAtBeginning(20);
    InsertAtEnd(30);
    InsertAtEnd(40);
    print(); // Should print: 20 10 30 40

    InsertInBetween(25, 10);
    print(); // Should print: 20 10 25 30 40

    deletion(10); // Delete middle node
    print(); // Should print: 20 25 30 40

    deletion(20); // Delete head node
    print(); // Should print: 25 30 40

    deletion(50); // Try to delete a non-existent node
    print(); // Should print: 25 30 40
    deletion(40);
    print();
    return 0;
}
