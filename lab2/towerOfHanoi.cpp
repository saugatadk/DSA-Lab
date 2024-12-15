#include<iostream>

using namespace std;

void printMove(int start, int end){
    cout << start << "->" << end <<endl;
}

void hanoi(int n, int start, int end){
    if(n==1){
        printMove(start, end);
    }else{
        int other = 6 - (start + end);
        hanoi(n-1, start ,other);
        printMove(start, end);
        hanoi(n-1, other, end);
    }
}


int main(){
    int n, start, end;
    cout << "Enter the number of discs in one column: ";
    cin >> n;
    cout << "Enter the start and end column: ";
    cin >> start >> end;
    hanoi(n,start,end);

    return 0;
}