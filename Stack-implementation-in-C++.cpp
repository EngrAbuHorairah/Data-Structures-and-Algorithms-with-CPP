#include <iostream>

using namespace std;

const int MAXSIZE = 100; // Maximum size of stack

class Stack {
private:
    int stack[MAXSIZE]; // Stack data structure
    int top; // Index of top element

public:
    Stack() { // Constructor
        top = -1; // Initialize top to -1
    }

    void push(int element) { // Add an element to the top of the stack
        if (top == MAXSIZE - 1) { // Check if stack is full
            cout << "Stack overflow!" << endl;
        } else {
            stack[++top] = element; // Increment top and add element to stack
        }
    }

    void pop() { // Remove the top element from the stack
        if (top == -1) { // Check if stack is empty
            cout << "Stack underflow!" << endl;
        } else {
            top--; // Decrement top to remove top element
        }
    }

    int topElement() { // Get the top element of the stack
        if (top == -1) { // Check if stack is empty
            cout << "Stack empty!" << endl;
            return -1;
        } else {
            return stack[top];
        }
    }

    bool empty() { // Check if the stack is empty
        return top == -1;
    }
};

int main() {
    Stack s; // Create a stack object
    int choice, element;

    while (true) { // Loop until user chooses to exit
        cout << "1. Push\n2. Pop\n3. Top\n4. Empty\n5. Exit" << endl; // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) { // Perform the selected operation
            case 1:
                cout << "Enter element: ";
                cin >> element;
                s.push(element);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.topElement() << endl;
                break;
            case 4:
                if (s.empty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}