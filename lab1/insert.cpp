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

    int element = 17;
    int position = 2;

    // Shift elements to the right
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    cout << "After adding 17 at position 2: ";
    printList(arr, size);

    return 0;
}