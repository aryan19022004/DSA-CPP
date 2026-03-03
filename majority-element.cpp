#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
-----------------------------------------
1️⃣ BRUTE FORCE APPROACH
-----------------------------------------
Logic:
- Har element ke liye pura array traverse karo
- Count karo kitni baar aa raha hai
- Agar count > n/2 ho gaya → majority element mil gaya

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int majorityBruteForce(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count > n/2) {
            return arr[i];
        }
    }

    return -1; // No majority element
}


/*
-----------------------------------------
2️⃣ BETTER APPROACH (Using Map)
-----------------------------------------
Logic:
- Map me frequency store karo
- Agar kisi ki frequency > n/2 ho jaye → return

Time Complexity: O(n log n)   (map takes log n)
Space Complexity: O(n)
*/
int majorityBetter(vector<int>& arr) {
    int n = arr.size();
    map<int,int> mp;

    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    for(auto it : mp) {
        if(it.second > n/2) {
            return it.first;
        }
    }

    return -1;
}


/*
-----------------------------------------
3️⃣ OPTIMAL APPROACH (Moore's Voting Algorithm)
-----------------------------------------
Logic:
Step 1: Candidate find karo
    - Agar count == 0 → new candidate choose karo
    - Same element → count++
    - Different element → count--

Step 2: Verify karo ki candidate really majority hai ya nahi

Time Complexity: O(n)
Space Complexity: O(1)
*/
int majorityOptimal(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    int candidate = -1;

    // Step 1: Find Candidate
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            candidate = arr[i];
            count = 1;
        }
        else if(arr[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Step 2: Verify Candidate
    count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == candidate) {
            count++;
        }
    }

    if(count > n/2) {
        return candidate;
    }

    return -1;
}


int main() {
    vector<int> arr = {1,1,1,1,12,14,14,14,14,14,14};

    cout << "Brute Force Answer: " << majorityBruteForce(arr) << endl;
    cout << "Better Approach Answer: " << majorityBetter(arr) << endl;
    cout << "Optimal Approach Answer: " << majorityOptimal(arr) << endl;

    return 0;
}
