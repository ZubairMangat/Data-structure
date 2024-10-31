/*
                              Linked List
linked list is a data structure
when data come then it create a box on memory
story	train ------>kachra
		Engine ---->important
		Bogi ----->Attch when it 1000kg
	Step 1. Create Engine (head)
	Step 2. Create bogi   (node)
	Step 3.fill bogi with kora  (fill data)
	step 4. Attach each other first one different then after all have same method
	step 5. if(first bogi){
		Attach with engine
	    }
		else 
		{
		Attach after last bogi}


	Engine ------> Head pointer
	Data container or box or bogi ----->node
Notes 
1)Head pointer should be point first node of linked list
2)Every node must connect to next node


*/

#include<iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;         // Data stored in the node
    Node* next;      // Pointer to the next node in the list
};

// Global variable to hold the head of the linked list
Node* head = nullptr;
// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int value) {
    Node* newNode = new Node; // Create a new node
    newNode->data = value;    // Set its value
    newNode->next = head;     // Link new node to the current head
    head = newNode;           // Update head to the new node
}
//function to insert at sppecific location
void insertAtSpecific(int value){
	Node* newNode=new Node;
	int data;
	cout<<"Enter the data that you want to add in node";
	cin>>data;
	newNode->data=data;
	newNode->next=nullptr;
	Node* th=head;
	if(head==nullptr){
		cout<<"The Linked list is empty";
	}
	else{
		while(th!=nullptr){
			if(th->data==value){
				newNode->next=th->next;
				th->next=newNode;
			}
			th=th->next;
		}

	}


}
// Function to insert a new node at the end of the linked list
void insertAtEnd(int value) {
    Node* newNode = new Node; // Create a new node
    newNode->data = value;    // Set its value
    newNode->next = nullptr;  // Initialize next pointer to nullptr

    if (head == nullptr) {
        head = newNode; // If the list is empty, set head to the new node
    } else {
        Node* currentNode = head; // Start from the head
        while (currentNode->next != nullptr) {    
            currentNode = currentNode->next; // Traverse to the last node
        }
        currentNode->next = newNode; // Link the last node to the new node
    }
}

void searchList(int target) {
    Node* currentNode = head; // Start from the head
    while (currentNode != nullptr) {
        if (currentNode->data == target) {
            cout << "Found: " << currentNode->data << endl;
            return; // Exit if found
        }
        currentNode = currentNode->next; // Move to the next node
    }
    cout << "Not Found" << endl; // If not found
}
void display(){
	Node *currentNode=head;
	while (currentNode!=nullptr){
		cout<<currentNode->data;
		currentNode=currentNode->next;
	}
	
}
// Function to traverse the linked list and display its elements
void traverseList() {
    Node* currentNode = head; // Start from the head
    while (currentNode != nullptr) {
        cout << currentNode->data << " "; // Print current node's data
        currentNode = currentNode->next;  // Move to the next node
    }
    cout << endl; // Print a new line at the end
}


// Function to clean up memory allocated for the linked list
void cleanupList() {
    Node* currentNode = head; // Start from the head
    while (currentNode != nullptr) {
        Node* nextNode = currentNode->next; // Store the next node
        delete currentNode;                   // Delete the current node
        currentNode = nextNode;               // Move to the next node
    }
}
// Function to display the linked list with index positions
void displayList() {
    Node* currentNode = head; // Start from the head
    int index = 0; // Initialize an index counter
    cout << "Linked List: ";
    while (currentNode != nullptr) {
        cout << "[" << index << ": " << currentNode->data << "] "; // Print index and data
        currentNode = currentNode->next; // Move to the next node
        index++; // Increment the index
    }
    cout << endl; // Print a new line at the end
}
void deletion()
{
    int x=0;
    cout <<"Enter the numbe that you want to delete :";
    cin>>x;
    Node* currentNode=head;
    Node* previousNode=nullptr;
    while(currentNode!=0&&currentNode->data!=x){
        previousNode=currentNode;
        currentNode=currentNode->next;
        if(currentNode==nullptr){
            cout<<"not present in list"<<endl;
        }
        else if (previousNode==nullptr){
            head=head->next;
            delete currentNode;
        }
        else {
            previousNode->next=currentNode->next;
            delete currentNode;

        }
        

    }

}
int main() {
// Node* head;
// Node* second;
// Node* third;
// Node* fourth;
// head = new Node;
// second = new Node;
// third = new Node;
// fourth = new Node;
// head->data = 23;
// head->next = second; 
// second->data = 39;
// second->next = third;
// third->data = 24;
// third->next = fourth;
// fourth->data = 53;
// fourth->next = NULL;
int choice ,value;
do 
{
	cout<<"Menu"<<endl;
	cout<<"1. InsertAtBegining"<<endl;
	cout<<"2. InsertAtEnd"<<endl;
	cout<<"3. Search number"<<endl;
	cout<<"4. Displaylist"<<endl;
	cout<<"5. Treverse the list"<<endl;
	cout<<"6. deletion "<<endl;
    cout<<"7. insert at sppecific location"<<endl;
	cout<<"8. Exit"<<endl;
	cout<<"Enter your Choice : ";
	cin>>choice;
	switch (choice)
	{
	case 1/* constant-expression */:
		/* code */
		cout <<"Enter the number : ";
		cin>>value;
		insertAtBeginning(value);
		break;
	case 2 /* constant-expression */:
		/* code */
		cout <<"Enter the number ";
		cin>>value;
		insertAtEnd(value);
		break;
	case 3/* constant-expression */:
		/* code */
		cout <<"Enter the number ";
		cin>>value;
		searchList(value);
		break;
	case 4/* constant-expression */:
		/* code */
		displayList();
		break;
	
	case 5 /* constant-expression */:
		/* code */
		traverseList();
		break;
	case 6/* constant-expression */:
		/* code */
		// cout <<"Enter the number ";
		// cin>>value;
		deletion();
		break;
	case 7/* constant-expression */:
		/* code */
		cout <<"Enter the that number jis kay bad tum add karna cha tay ho :  ";
		cin>>value;
		insertAtSpecific(value);
		break;
	case 8 /* constant-expression */:
		/* code */

		cleanupList();
		break;
	
	default:
		cout<<"Enter number 1 to 8";
		break;
	}

}while(choice!=8);
    return 0; // End of the program
}




