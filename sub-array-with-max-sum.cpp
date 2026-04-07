// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int global_max = INT_MIN;
    int sum = 0;
    for(int i =0;i<arr.size();i++){
        sum+=arr[i];
        if(global_max<sum){
            global_max = sum;
        }
        
        if(sum<0){
            sum = 0;
        }
    }
    
    cout<<global_max;
    
    return 0;
}
