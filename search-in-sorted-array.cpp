#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
   public:
       int SearchInRotatedArray(vector<int>&arr,int target){
          int left = 0,right = arr.size()-1;

          while(left<=right){
            int mid = (left + right)/2;
            if(arr[mid] == target){
                return mid;
            }else if(arr[left]<=arr[mid]){
               if(arr[left]<=target && target<arr[mid]){
                  right = mid -1;
               }else{
                 left = mid + 1;
               }
            }else{
               if(arr[mid]<target && target<=arr[right]){
                left = mid +1;
               }else{
                  right = mid -1;
               }
            }
          }

          return -1;
       }

};

int main() {


    vector<int> arr = {5,6,7,8,9,10,1,2,3,4};
    Solution s1 ;
    int indx = s1.SearchInRotatedArray(arr,3);
    cout<<indx<<" This is the index of your target ";
    return 0;
}
