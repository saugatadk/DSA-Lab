#include<iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

bool isempty(){
    if(front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}

void enqueue(int value){
    if(rear == SIZE-1){
        cout << "Queue is full\n";
    }else{
        if(front == -1)
            front = 0;//inserting 1st element
        rear++;
        A[rear] = value;
        cout << "Enqueued Value: " << A[rear] << endl;
    }
}

void dequeue(){
    if(isempty()){
        cout << "Queue is empty\n";
    }else{
        if(front == rear){
            front = rear = -1;
        }else{
            cout << "Dequeued Value: " << A[front] << endl;
            front++;
        }
    }
}


void displayQueue(){
    if(isempty()){
        cout << "Queue is empty\n";
    }else{
        for(int i = front; i <= rear; i++){
            cout << A[i] << " ";
        }
    }
}

int main(){
    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(9);
    enqueue(10);
    dequeue();
    dequeue();
    dequeue();
    enqueue(11);
    displayQueue();
    return 0;
}