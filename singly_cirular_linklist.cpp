#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;
};

// Circular Singly Linked List class definition
class CircularSinglyLinkedList {
private:
    Node* head; // pointer to head node
public:
    // constructor
    CircularSinglyLinkedList() {
        head = nullptr;
    }

    // insert node at beginning of list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            head->next = head; // make head point to itself for circular property
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // insert node at end of list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            head->next = head; // make head point to itself for circular property
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // delete node with given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        while (current->data != value) {
            if (current->next == head) {
                cout << "Value not found in list." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        if (current == head && current->next == head) {
            head = nullptr;
            delete current;
            return;
        }
        if (current == head) {
            previous = head;
            while (previous->next != head) {
                previous = previous->next;
            }
            head = current->next;
            previous->next = head;
            delete current;
        }
        else if (current->next == head) {
            previous->next = head;
            delete current;
        }
        else {
            previous->next = current->next;
            delete current;
        }
    }

    // display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Circular Singly Linked List: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

// main function
int main() {
    CircularSinglyLinkedList cll;

	int op, size, num;
	while(true)
	{
		cout<<"\n--------------------------------------------------\n";
		cout<<"\t1. Insertion\n";
		cout<<"\t2. Deletion\n";
		cout<<"\t3. Show\n";
		cout<<"\t4. Exit";
		cout<<"\n--------------------------------------------------\n";
		
		cout<<"Choose an option = ";
		cin>>op;
		
		char op2;
		int dltnum;
		
		switch(op)
		{
			case 1:
				cout<<"\nEnter S for start and E for end = ";
				cin>>op2;
				switch(op2)
				{
					case 'S':
						cout<<"\nHow many elements you want to push = ";
						cin>>size;
						for(int i = 0; i<size; i++)
						{
							cout<<"Enter new element = ";
							cin>>num;
							cll.insertAtBeginning(num);
						}
						break;
					case 'E':
						cout<<"How many elements you want to push = ";
						cin>>size;
						for(int i = 0; i<size; i++)
						{
							cout<<"Enter new element = ";
							cin>>num;
							cll.insertAtEnd(num);
						}
						break;
					default:
						cout<<"Invalid entry !!!"<<endl;
				}
				break;
			case 2:
				cout<<"Which node you want to delelte = ";
				cin>>dltnum;
				cll.deleteNode(dltnum);
				break;
			case 3:
				cll.display();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"Invalid Entry !!!"<<endl;
		}
	}
	

    return 0;
}
