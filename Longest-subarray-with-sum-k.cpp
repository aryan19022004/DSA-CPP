#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
============================================================
1️⃣ BRUTE FORCE APPROACH (O(n³))
------------------------------------------------------------
Logic:
1. Fix start index (i)
2. Fix end index (j)
3. Calculate sum from i to j using third loop
4. If sum == target, update maxLength

Time Complexity: O(n³)
Space Complexity: O(1)
============================================================
*/
int longestSubarrayBrute(vector<int> &v, int target) {

    int n = v.size();
    int maxLength = 0;

    for(int i = 0; i < n; i++) {

        for(int j = i; j < n; j++) {

            int sum = 0;

            for(int k = i; k <= j; k++) {
                sum += v[k];
            }

            if(sum == target) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}


/*
============================================================
2️⃣ BETTER APPROACH (O(n²)) – Running Sum
------------------------------------------------------------
Logic:
1. Fix start index (i)
2. Maintain running sum
3. Extend end index (j)
4. If sum == target → update maxLength

Time Complexity: O(n²)
Space Complexity: O(1)
============================================================
*/
int longestSubarrayBetter(vector<int> &v, int target) {

    int n = v.size();
    int maxLength = 0;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += v[j];

            if(sum == target) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}


/*
============================================================
3️⃣ OPTIMAL APPROACH (O(n)) – Sliding Window
------------------------------------------------------------
⚠ Works only when all elements are POSITIVE

Logic:
1. Use two pointers (left, right)
2. Expand right pointer
3. If sum > target → shrink from left
4. If sum == target → update maxLength

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/
int longestSubarrayOptimal(vector<int> &v, int target) {

    int n = v.size();
    int left = 0;
    int sum = 0;
    int maxLength = 0;

    for(int right = 0; right < n; right++) {

        sum += v[right];

        while(sum > target && left <= right) {
            sum -= v[left];
            left++;
        }

        if(sum == target) {
            maxLength = max(maxLength, right - left + 1);
        }
    }

    return maxLength;
}



int main() {

    vector<int> v = {1,2,3,4,5};
    int target = 9;

    cout << "Brute Force Answer: "
         << longestSubarrayBrute(v, target) << endl;

    cout << "Better Approach Answer: "
         << longestSubarrayBetter(v, target) << endl;

    cout << "Optimal Approach Answer: "
         << longestSubarrayOptimal(v, target) << endl;

    return 0;
}
