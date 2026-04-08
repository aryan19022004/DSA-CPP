#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,2,2,3,3,3,4,5};
    int n = arr.size();

    // check first element
    if(arr[0] != arr[1]){
        cout << arr[0]<<" ";
    }

    // check middle elements
    for(int i = 1; i < n-1; i++){
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
            cout << arr[i]<<" ";
          
        }
    }

    // check last element
    if(arr[n-1] != arr[n-2]){
        cout << arr[n-1]<<" ";
    }

    return 0;
}
