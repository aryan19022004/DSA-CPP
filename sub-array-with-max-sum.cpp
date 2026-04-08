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


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    int sum = 0, maxSum = INT_MIN;
    int start = 0, end = 0, tempStart = 0;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];

        if(sum > maxSum){
            maxSum = sum;
            start = tempStart;
            end = i;
        }

        if(sum < 0){
            sum = 0;
            tempStart = i + 1; // new subarray start
        }
    }

    cout << "Max Sum: " << maxSum << endl;
    cout << "Subarray: ";

    for(int i = start; i <= end; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
