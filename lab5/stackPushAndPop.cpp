#include <iostream>
#define MAX 10

using namespace std;

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; } 

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed to stack.\n";
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
        } else {
            int value = arr[top];
            top--;
            cout << value << " popped from stack.\n";
        }
    }

    void peek() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element is: " << arr[top] << "\n";
        }
    }

    bool isEmpty() {
        return (top < 0) ? true : false;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.peek();
    stack.pop();
    stack.pop();
    stack.peek();
    return 0;
}