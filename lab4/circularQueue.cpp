#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

bool isempty() {
    if (front == -1 && rear == -1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is full\n";
    } else {
        if (front == -1) 
            front = 0;  // inserting 1st element
        rear = (rear + 1) % SIZE;
        A[rear] = value;
    }
}

void dequeue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void showfront() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "\nElement at front is: " << A[front];
    }
}

void displayQueue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        int i;
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                cout << A[i] << " ";
            }
        } else {
            i = front;
            while (i < SIZE) {
                cout << A[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear) {
                cout << A[i] << " ";
                i++;
            }
        }
    }
}

int main() {
    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(9);
    dequeue();
    dequeue();
    enqueue(17);
    enqueue(10);
    displayQueue();
    showfront();
    return 0;
}