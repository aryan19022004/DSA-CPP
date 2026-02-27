//Two sum problem in array 
//Brute Force
#include <iostream>
using namespace std;
int main() {
    int arr[] = {6,8,3,9,4,5};
    int target = 13;
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i =0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
              cout << "Number whose sum is " << target 
     << " are " << arr[i] << " " << arr[j] << endl;
                break;
            }
        }
    }
    return 0;
}

