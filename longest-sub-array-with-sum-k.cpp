// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;


int main() {
    vector<int> v = {2,9,8,7,5,8,5,5,5,5,5,4};
    vector<int> result;
    int target  = 29;
    int n = v.size();
    int sum = 0;
    int max_len = 0;
    int i = 0;
    for(int j = 0;j<n;j++){
        sum += v[j];
        while(sum>target && i < j){
            sum -= v[i];
            i++;
        }
        if(sum == target){
          max_len = max(max_len, j - i +1);
        }
    }
    
    cout<<"Longest subarray which have the sum = "<<target<<" is "<<max_len;
  
    return 0;
}

#include <unordered_map>

int longestSubarrayOptimal(vector<int>& v, int k) {
    unordered_map<int, int> mp;  // prefixSum -> first index
    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < v.size(); i++){
        sum += v[i];

        if(sum == k){
            maxLen = i + 1;
        }

        if(mp.find(sum - k) != mp.end()){
            maxLen = max(maxLen, i - mp[sum - k]);
        }

        // store only first occurrence
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    return maxLen;
}
