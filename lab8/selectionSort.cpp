#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++ ){
        int smallestIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
};

void printArray(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
};

int main(){
    vector<int> arr = {4, 1, 5, 2, 3};
    selectionSort(arr);
    printArray(arr);
    return 0;
}