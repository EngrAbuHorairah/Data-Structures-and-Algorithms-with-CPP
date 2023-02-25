#include <iostream>
using namespace std;

#define SIZE 5 // define the maximum size of the circular queue

// Class for circular queue
class CircularQueue {
private:
    int items[SIZE]; // array to store the elements in the circular queue
    int front, rear; // pointers to keep track of the front and rear of the circular queue

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the circular queue is full
    bool isFull() {
        return ((rear+1)%SIZE == front);
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to add an element to the circular queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Circular Queue is full\n";
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear+1)%SIZE; // use rear+1 % SIZE to implement circular nature of the queue
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    // Function to remove an element from the circular queue
    int dequeue() {
        int element;
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
            return -1;
        } else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front+1)%SIZE; // use front+1 % SIZE to implement circular nature of the queue
            }
            return element;
        }
    }

    // Function to display the elements in the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
        } else {
            int i;
            cout << "Circular Queue elements are:\n";
            for (i = front; i != rear; i = (i+1)%SIZE) { // use i = (i+1) % SIZE to implement circular nature of the queue
                cout << items[i] << endl;
            }
            cout << items[i] << endl; // print the last element separately
        }
    }
};

// Main function
int main() {
    CircularQueue q;

    int choice, element, size;

    do {
        // display menu
        cout << "\n-----------------------------------------------\n";
        cout << "\t1. Enqueue\n";
        cout << "\t2. Dequeue\n";
        cout << "\t3. Display\n";
        cout << "\t4. Exit";
        cout << "\n-----------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        	cout<<"How many elements you want to insert = ";
        	cin>>size;
        	for(int i=0; i<size; i++)
			{
	            cout << "Enter the element to be inserted = ";
	            cin >> element;
	            q.enqueue(element);
        	}
            break;
        case 2:
            element = q.dequeue();
            if (element != -1) {
                cout << "Deleted element is: " << element << endl;
            }
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}