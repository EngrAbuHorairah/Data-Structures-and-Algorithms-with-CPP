#include <iostream>
using namespace std;

// Node class for circular queue
class Node {
    public:
        int data;
        Node* next;
};

// Circular queue class
class CircularQueue {
    private:
        Node* rear; // pointer to last element of the queue
    public:
        CircularQueue() {
            rear = NULL;
        }

        // function to check if the queue is empty
        bool isEmpty() {
            return (rear == NULL);
        }

        // function to insert an element at the rear of the queue
        void enqueue(int data) {
            Node* newNode = new Node(); // create a new node
            newNode->data = data;
            if (rear == NULL) {
                rear = newNode; // if queue is empty, set rear to the new node
                newNode->next = rear; // set next of new node to itself, making it circular
            } else {
                newNode->next = rear->next; // set next of new node to the front of the queue
                rear->next = newNode; // set next of rear to the new node
                rear = newNode; // set rear to the new node
            }
            cout << "Element " << data << " enqueued to the queue." << endl;
        }

        // function to remove an element from the front of the queue
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
            } else {
                Node* temp = rear->next; // pointer to the front of the queue
                if (rear->next == rear) {
                    rear = NULL; // if there is only one element, set rear to NULL
                } else {
                    rear->next = rear->next->next; // set next of rear to the next of front
                }
                cout << "Element " << temp->data << " dequeued from the queue." << endl;
                delete temp; // free memory allocated for the front node
            }
        }

        // function to display the elements of the queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
            } else {
                Node* temp = rear->next; // pointer to the front of the queue
                cout << "Elements of the queue are: ";
                do {
                    cout << temp->data << " ";
                    temp = temp->next;
                } while (temp != rear->next); // iterate till the end of the queue is reached
                cout << endl;
            }
        }
};

// main function to demonstrate the circular queue operations
int main() {
    CircularQueue cq; // create a circular queue object
    int choice, data;
    while (true) {
        // display menu
        cout << "Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> data;
                cq.enqueue(data);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                exit(0); // exit the program
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}