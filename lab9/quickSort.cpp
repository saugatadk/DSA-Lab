#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pindx = partition(arr, low, high);

        quickSort(arr, low, pindx - 1);
        quickSort(arr, pindx + 1, high);
    }
}

void printArray( vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 4};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    printArray(arr);
    return 0;
}