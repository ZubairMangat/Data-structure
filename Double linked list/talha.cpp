#include<iostream>
#include<windows.h>
using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;

	node(int num)
	{
		this->data = num;
		this->prev = nullptr;
		this->next = nullptr;
	}
};

int node_count = 0;
node* head = NULL;
node* tail = NULL;

void display()	//reverse printing
{
	node* temp = tail;

	if (tail == NULL)
	{
		cout << "List currently empty\n";
		return;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->prev;
		}
		cout << endl;
	}
}
void insert_end()
{
	cout << "Enter data: ";
	int num;
	cin >> num;
	node* p = new node(num);

	if (tail == NULL)
	{
		head = p;
		tail = p;
		cout << "List currently empty. Node added as first node.\n";
	}
	else
	{
		tail->next = p;	//initial tail next now points to p, the new tail
		p->prev = tail;	//new node prev now points to initial tail
		tail = p;		//tail is updatad to be p
		cout << "Node added\n";
	}
	node_count++;
}
void insert_start()
{
	cout << "Enter data: ";
	int num;
	cin >> num;
	node* p = new node(num);

	if (tail == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		node* temp = tail;
		while (temp->prev != NULL)	//loop ultimately points to the head
		{
			temp = temp->prev;
		}
		p->next = temp;	//new node p now points to initial head
		temp->prev = p;	//initial head prev now points to new head p
		head = p;		//head is updatad to be new node p
	}
	cout << "Node added at start\n";
	node_count++;
}
void insert_after_specific_value(int value)
{
	cout << "Enter data: ";
	int num;
	cin >> num;
	node* p = new node(num);
	node* temp = tail;

	if (temp == NULL)
	{//if list is empty, inserted as first node
		head = p;
		tail = p;
		cout << "List empty. Inserted as first node\n";
		node_count++;
		return;
	}

	while (temp != NULL)
	{//search for value
		if (temp->data == value)
		{
			break;
		}
		temp = temp->prev;
	}

	if (temp == NULL)
	{
		cout << "Value not found\nInserted as last node\n";
		p->prev = tail;
		tail->next = p;
		tail = p;
	}
	else
	{
		p->prev = temp;
		p->next = temp->next;

		if (temp->next != NULL) //check to see if the value is found at the last node by seeing if next is NULL
		{//if not, means there is a node after the desired value; we have that node's prev point to p
			temp->next->prev = p;
		}
		else
		{//if yes, p becomes the new tail
			tail = p;
		}
		temp->next = p;
		cout << "Insertion successful\n";
	}
	node_count++;
}
void insert_specific_index(int index)
{
	if (index < 1 || index > node_count)
	{
		cout << "Index does not exist.\n";
		return;
	}


	cout << "Enter data: ";
	int num;
	cin >> num;
	node* p = new node(num);


	if (tail == NULL)
	{
		cout << "List currently empty. Inserted as first node./n";
		head = p;
		tail = p;
	}
	else if (index == 1)
	{//in case node is to be attached as first node
		p->next = head;
		head->prev = p;
		head = p;
	}
	else
	{//new node to be attached anywhere else
		if (index == node_count+ 1)
		{//if by chance the preferred index is 1 greater than the last index in the list, new node is to be attached to tail
			p->prev = tail;
			tail->next = p;
			tail = p;
		}
		else
		{
			node* temp = tail;
			for (int i = node_count; i > index; i--)
			{//reverse traverse to 1 ahead of index
				temp = temp->prev;
			}

			p->next = temp;			//new node p next now points to temp
			p->prev = temp->prev;	//new node p prev now points to previous index/node
			temp->prev = p;
			p->prev->next = p;
		}
	}
	node_count++;
	cout << "Node successfully attached\n";
}
void insert_middle()
{
	cout << "Enter data: ";
	int num;
	cin >> num;
	node* p = new node(num);
	
	if (tail == NULL)
	{
		head = p;
		tail = p;
		cout << "List currently empty. Node added as first node.\n";
		node_count++;
		return;
	}
	
	node* temp = tail;
	if (node_count % 2 == 0) 
	{
		for (int i = node_count; i > node_count / 2; i--)
		{//reverse traverse to 1 ahead of middle
			temp = temp->prev;
		}
	}
	else
	{
		for (int i = node_count; i > (node_count / 2) + 1; i--)
		{//reverse traverse to 1 ahead of middle
			temp = temp->prev;
		}
	}
	p->next = temp->next;			//new node p next now points to node after temp
	p->prev = temp;					//new node p prev now points to temp
	temp->next = p;
	p->next->prev = p;
	node_count++;
}
void delete_end()
{
	if (head == NULL)
	{
		cout << "List is empty\n";
		return;
	}

	if (node_count == 1)
	{
		node* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else
	{
		node* temp = tail;
		tail = temp->prev;
		delete temp;
	}
	node_count--;
}
void delete_start()
{
	if (head == NULL)
	{
		cout << "List is empty\n";
		return;
	}

	node* temp = tail;
	if (node_count == 1)
	{		
		head = NULL;
		tail = NULL;
	}
	else
	{
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}
		head = head->next;
		delete temp;
	}
	node_count--;
}
void delete_middle()
{
	if (tail == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	node* temp = head;
	if (node_count == 1)
	{
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else
	{
		if (node_count % 2 == 1)
		{
			for (int i = node_count; i > (node_count / 2) + 1; i--)
			{//reverse traverse to middle
				temp = temp->prev;
			}
		}
		else
		{
			for (int i = node_count; i > (node_count / 2) + 1; i--)
			{//reverse traverse to 1 ahead of middle
				temp = temp->prev;
			}
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		node_count--;
	}
}
void menu()
{
	cout << "Select an option by entering the corresponding number\n";
	cout << "1. Display list in reverse\n";
	cout << "2. Insert at Start\n";
	cout << "3. Insert at End\n";
	cout << "4. Insert after some Value\n";
	cout << "5. Insert at some Index\n";
	cout << "6. Insert in the Middle\n";
	cout << "7. Delete from Start\n";
	cout << "8. Delete from End\n";
	cout << "9. Delete from Middle\n";
	cout << "0. Exit\n";
}
void return_to_menu()
{
	cout << "Press any key to return to the Menu";
	cin.ignore();
	cin.get();
	system("CLS");
}

int main()
{
	int option;
	do
	{
		menu();
		cin >> option;
		switch (option)
		{
		case 0:
			cout << "Program terminated\n";
			break;

		default:
			while (option < 1 || option>9)
			{
				cout << "\x1b[A" << "\r" << "Invalid option. Re-enter:";
				cin >> option;
			}
			break;

		case 1:
			system("CLS");
			display();
			return_to_menu();
			break;

		case 2:
			system("CLS");
			insert_start();
			return_to_menu();
			break;

		case 3:
			system("CLS");
			insert_end();
			return_to_menu();
			break;

		case 4:
			system("CLS");
			int value;
			cout << "Enter the value after which to insert: ";
			cin >> value;
			insert_after_specific_value(value);
			return_to_menu();
			break;

		case 5:
			system("CLS");
			int index;
			cout << "Enter the index at which to insert: ";
			cin >> index;
			insert_specific_index(index);
			return_to_menu();
			break;

		case 6:
			system("CLS");
			insert_middle();
			return_to_menu();
			break;

		case 7:
			system("CLS");
			delete_start();
			return_to_menu();
			break;

		case 8:
			system("CLS");
			delete_end();
			return_to_menu();
			break;

		case 9:
			system("CLS");
			delete_middle();
			return_to_menu();
			break;

		}
	} while (option != 0);
	return 0;
}