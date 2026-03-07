#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
====================================================
1) BRUTE FORCE APPROACH
====================================================

Logic:
1. Har element ke right side ke sab elements check karo.
2. Agar right side me koi bhi element current element se bada mil jaye,
   to current element leader nahi hai.
3. Agar right side me koi bada element nahi mila -> leader hai.

Example:
10 22 12 3 0 6

22 ke right side me koi bada nahi -> leader
12 ke right side me koi bada nahi -> leader
6 ke right side me koi nahi -> leader

Time Complexity: O(n^2)
(two nested loops)

Space Complexity: O(1)
(no extra data structure used)
*/

void leadersBruteForce(vector<int> arr){

    int n = arr.size();

    cout << "Leaders (Brute Force): ";

    for(int i = 0; i < n; i++){

        bool leader = true;

        for(int j = i + 1; j < n; j++){

            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }

        if(leader){
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}


/*
====================================================
2) BETTER APPROACH
====================================================

Logic:
1. Array ko right se traverse karo.
2. Ek result vector maintain karo.
3. Sabse pehle last element leader hota hai.
4. Agar current element result.back() se bada hai
   to wo bhi leader hai.

Example:
10 22 12 3 0 6

Right traversal:
6 -> leader
12 > 6 -> leader
22 > 12 -> leader

Time Complexity: O(n)

Space Complexity: O(n)
(extra result vector used)
*/

void leadersBetter(vector<int> arr){

    int n = arr.size();

    vector<int> result;

    for(int i = n - 1; i >= 0; i--){

        if(result.empty()){
            result.push_back(arr[i]);
        }
        else if(arr[i] > result.back()){
            result.push_back(arr[i]);
        }
    }

    cout << "Leaders (Better): ";

    for(auto it : result){
        cout << it << " ";
    }

    cout << endl;
}


/*
====================================================
3) OPTIMAL APPROACH
====================================================

Logic:
1. Right side ka maximum element track karo.
2. Variable maxRight maintain karo.
3. Agar arr[i] > maxRight hai
   to arr[i] leader hai.
4. Fir maxRight update kar do.

Example:
10 22 12 3 0 6

Right traversal:
6 > -inf -> leader
12 > 6 -> leader
22 > 12 -> leader

Time Complexity: O(n)

Space Complexity: O(1)
(no extra array used)
*/

void leadersOptimal(vector<int> arr){

    int n = arr.size();

    int maxRight = INT_MIN;

    cout << "Leaders (Optimal): ";

    for(int i = n - 1; i >= 0; i--){

        if(arr[i] > maxRight){
            cout << arr[i] << " ";
            maxRight = arr[i];
        }
    }

    cout << endl;
}


int main(){

    vector<int> arr = {10,22,12,3,0,6};

    leadersBruteForce(arr);
    leadersBetter(arr);
    leadersOptimal(arr);

    return 0;
}
