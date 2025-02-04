#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr ={2,3,4,10,40,10};
    int target = 10;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            cout << "Element found at index: " << i << endl;
        }
    }
    return 0;
}