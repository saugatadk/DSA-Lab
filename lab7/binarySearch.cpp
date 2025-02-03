#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> arr ={2,3,4,10,40};
    int target = 10;
    
    int left = 0;
    int right = arr.size() - 1;
    int location = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target){
            location = mid;
            break;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    if(location != -1){
        cout << "Element found at index: " << location << endl;
    }else{
        cout << "Element not found in the array." << endl;
    }

    return 0;
}