#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
   public:
       int minimumInSortedArray(vector<int>&arr){
          int left = 0,right = arr.size() -1;
          while(left<right){
            int mid = (left + right)/2;
            if(arr[mid]>arr[right]){
                left = mid+1;
            }else{
               right = mid;
            }
          }

          return arr[left];
       }

};

int main() {


    vector<int> arr = {5,6,7,8,9,10,1,2,3,4};
    Solution s1 ;
  
    int minimum = s1.minimumInSortedArray(arr);
    cout<<indx<<" This is the index of your target "<<endl;
    cout<<minimum<<" Is the minimum element of the array ";
    return 0;
}
