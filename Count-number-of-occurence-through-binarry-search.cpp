#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int LowerBound(vector<int>&arr, int target)
{
    int n = arr.size();
    int left = 0,right = n-1;

    int ans = -1;
    while(left<=right)
    {
        int mid = (left + right)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            right = mid -1;
        }
        else if(arr[mid]<target)
        {
            left = mid +1;
        }
        else
        {
            right = mid -1;
        }
    }

    return ans;
}

int UpperBound(vector<int> arr,int target)
{
    int n = arr.size();
    int left = 0,right = n-1;

    int ans = -1;
    while(left<=right)
    {
        int mid = (left + right)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            left = mid +1;
        }
        else if(arr[mid]<target)
        {
            left = mid +1;
        }
        else
        {
            right = mid -1;
        }
    }

    return ans;
}

void count(vector<int>arr,int target){
    int n = arr.size();
    int lower = LowerBound(arr,target);
    if(lower == -1){
        cout<<"0 times";
        return;
    }
    int upper = UpperBound(arr,target);
    int count = upper - lower + 1;

    cout<<count<<" times the target is present in the array";
}

int main()
{
    vector<int> arr = {1,1,1,1,2,2,2,2,2,2,2,2,3,3,4,5,6,7,8,9};

   count(arr,10);
 return 0;
}







    return 0;
}
