#include <iostream>
using namespace std;

void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5}; 
    int size = 5;


    int position = 2;

    // Shift elements to the left
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "After removing element at position 2: ";
    printList(arr, size);

    return 0;
}