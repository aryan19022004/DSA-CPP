#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------
BRUTE FORCE APPROACH
------------------------------------------------
Logic:
Check every possible triplet using 3 loops.

Equation:
arr[i] + arr[j] + arr[k] == target

Steps:
1. Run 3 nested loops
2. Check sum of every combination
3. If sum == target, store the triplet

Time Complexity: O(n^3)
Space Complexity: O(1) (excluding result storage)
*/

void bruteForce(vector<int> arr, int target){

    int n = arr.size();
    set<vector<int>> ans; // to avoid duplicate triplets

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){

                if(arr[i] + arr[j] + arr[k] == target){

                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }
    }

    cout<<"Brute Force Triplets:\n";

    for(auto it : ans){
        for(int x : it) cout<<x<<" ";
        cout<<endl;
    }
}


/*
------------------------------------------------
BETTER APPROACH (Hashing / Set)
------------------------------------------------
Logic:
Fix one element and reduce the problem to 2Sum.

Equation:
a + b + c = target
c = target - (a + b)

Steps:
1. Fix arr[i]
2. Use set to store visited numbers
3. Calculate third = target - (arr[i] + arr[j])
4. If third exists in set -> triplet found

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

void better(vector<int> arr, int target){

    int n = arr.size();
    set<vector<int>> ans;

    for(int i = 0; i < n; i++){

        set<int> st;

        for(int j = i+1; j < n; j++){

            int third = target - (arr[i] + arr[j]);

            if(st.find(third) != st.end()){

                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }

            st.insert(arr[j]);
        }
    }

    cout<<"\nBetter Approach Triplets:\n";

    for(auto it : ans){
        for(int x : it) cout<<x<<" ";
        cout<<endl;
    }
}


/*
------------------------------------------------
OPTIMAL APPROACH (Two Pointer)
------------------------------------------------
Logic:
1. Sort the array
2. Fix one element
3. Use two pointers (left and right)

Steps:
1. Sort array
2. Fix arr[i]
3. left = i+1 , right = n-1
4. Check sum

If sum == target -> triplet found
If sum < target -> increase left
If sum > target -> decrease right

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

void optimal(vector<int> arr, int target){

    int n = arr.size();
    sort(arr.begin(), arr.end());

    cout<<"\nOptimal Approach Triplets:\n";

    for(int i = 0; i < n; i++){

        if(i > 0 && arr[i] == arr[i-1]) continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right){

            int sum = arr[i] + arr[left] + arr[right];

            if(sum == target){

                cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;

                left++;
                right--;

                while(left < right && arr[left] == arr[left-1]) left++;
                while(left < right && arr[right] == arr[right+1]) right--;
            }

            else if(sum < target){
                left++;
            }

            else{
                right--;
            }
        }
    }
}


/*
------------------------------------------------
MAIN FUNCTION
------------------------------------------------
Calls all three approaches
*/

int main(){

    vector<int> arr = {1,2,3,4,5,6};
    int target = 10;

    bruteForce(arr, target);
    better(arr, target);
    optimal(arr, target);

}
