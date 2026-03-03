// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;


int main() {
    vector<int> v = {2,9,8,7,5,8};
    vector<int> result;
    int target  = 17;
    int n = v.size();
    int sum = 0;
    int i = 0;
    for(int j = 0;j<n;j++){
        sum += v[j];
        while(sum>target && i < j){
            sum -= v[i];
            i++;
        }
        if(sum == target){
            while(i<=j){
                cout<<v[i]<<" ";
                i++;
            }
        }
    }
  
    return 0;
}
