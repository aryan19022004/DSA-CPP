#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
----------------------------------------------------
Brute Force Approach
----------------------------------------------------

Logic:
For every element, count how many times it appears
consecutively by checking the next elements.

Steps:
1. Start from index i
2. Count same numbers forward
3. Update maximum count
4. Repeat for every element

Time Complexity  : O(n^2)
Space Complexity : O(1)
*/

int bruteForce(vector<int> &arr){

    int n = arr.size();
    int maxCount = 0;

    for(int i = 0; i < n; i++){

        int count = 1;

        for(int j = i + 1; j < n; j++){

            if(arr[j] == arr[i]){
                count++;
            }
            else{
                break;
            }

        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}



/*
----------------------------------------------------
Optimal Approach (Single Traversal)
----------------------------------------------------

Logic:
Since the array is sorted, equal elements appear
together.

Steps:
1. Traverse array once
2. Compare current element with previous element
3. If same -> increase count
4. If different -> update maxCount and reset count

Time Complexity  : O(n)
Space Complexity : O(1)
*/

int optimalSolution(vector<int> &arr){

    int n = arr.size();

    int count = 1;
    int maxCount = 1;

    for(int i = 1; i < n; i++){

        if(arr[i] == arr[i-1]){
            count++;
        }
        else{
            maxCount = max(maxCount, count);
            count = 1;
        }

    }

    // Final check for last sequence
    maxCount = max(maxCount, count);

    return maxCount;
}



int main(){

    vector<int> arr = {1,1,1,1,1,2,2,2,3,3,7,7,7,7,7,7,7};

    cout << "Brute Force Answer: " << bruteForce(arr) << endl;

    cout << "Optimal Solution Answer: " << optimalSolution(arr) << endl;

    return 0;
}
