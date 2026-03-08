#include <iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};

    int k = 3;
    int sum = 0;
    int count = 0;

    map<int,int> mp;

    mp[0] = 1;

    for(int i = 0;i<arr.size();i++){

        sum += arr[i];

        if(mp.find(sum-k) != mp.end()){
            count += mp[sum-k];
        }

        mp[sum]++;
    }

    cout<<"Total subarrays with sum "<<k<<" is "<<count;

}
