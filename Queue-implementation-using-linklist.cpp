#include<iostream>

using namespace std;

// Define a class Node to represent each node in the linked list

class Node {

public:

    int data;

    Node* next;

};

// Define a class Queue to represent the queue data structure

class Queue {

private:

    Node *front, *rear; // Pointers to the front and rear of the queue

public:

    Queue() { // Constructor to initialize front and rear pointers to NULL

        front = NULL;

        rear = NULL;

    }

    void enqueue(int value) { // Function to add an element to the queue

        Node* temp = new Node(); // Create a new node to store the value

        temp->data = value; // Assign the value to the data field of the node

        temp->next = NULL; // Set the next field to NULL

        if(front == NULL && rear == NULL) { // If the queue is empty

            front = rear = temp; // Set both front and rear pointers to the new node

            return;

        }

        rear->next = temp; // Otherwise, set the next field of the current rear to the new node

        rear = temp; // Set the rear pointer to the new node

    }

    void dequeue() { // Function to remove an element from the queue

        Node* temp = front; // Create a pointer to the front of the queue

        if(front == NULL) { // If the queue is empty

            cout<<"Queue is empty"<<endl; // Print an error message and return

            return;

        }

        if(front == rear) { // If there is only one element in the queue

            front = rear = NULL; // Set both front and rear pointers to NULL

        }

        else { // Otherwise

            front = front->next; // Set the front pointer to the next element in the queue

        }

        delete temp; // Delete the node pointed to by the temp pointer

    }

    void display() { // Function to display the elements in the queue

        Node* temp = front; // Create a pointer to the front of the queue

        while(temp != NULL) { // While the pointer is not NULL

            cout<<temp->data<<" "; // Print the data field of the node

            temp = temp->next; // Move the pointer to the next node

        }

        cout<<endl; // Print a newline character after the last element

    }

};

int main() {

    Queue q; // Create a new instance of the Queue class

    int choice, value; // Variables to store the user's choice and input value

    while(true) { // Loop indefinitely until the user chooses to exit

        cout<<"1.Enqueue"<<endl; // Display the menu options

        cout<<"2.Dequeue"<<endl;

        cout<<"3.Display"<<endl;

        cout<<"4.Exit"<<endl;

        cout<<"Enter your choice: ";

        cin>>choice; // Read the user's choice from standard input

        switch(choice) { // Execute the corresponding function based on the user's choice

            case 1:

                cout<<"Enter the value to be inserted: ";

                cin>>value;

                q.enqueue(value);

                break;

            case 2:

                q.dequeue();

                break;

            case 3:

                q.display();

                break;

            case 4:

                exit(0); // Exit the program

            default:

                cout<<"Invalid choice"<<endl; // Print an error message for an invalid choice

        }

    }

    return 0;

}
