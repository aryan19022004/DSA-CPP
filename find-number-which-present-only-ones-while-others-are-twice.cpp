#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
============================================================
BRUTE FORCE APPROACH
------------------------------------------------------------
Logic:
1. For every element:
      - Count how many times it appears in entire array.
2. If count == 1 → print that element.

Time Complexity:
- Outer loop: n
- Inner loop: n
- Overall: O(n²)

Space Complexity:
- O(1) (no extra space)
============================================================
*/

int findUsingBrute(vector<int> &v) {

    for(int i = 0; i < v.size(); i++) {

        int count = 0;

        for(int j = 0; j < v.size(); j++) {
            if(v[i] == v[j]) {
                count++;
            }
        }

        if(count == 1) {
            return v[i];
        }
    }

    return -1;
}

/*
============================================================
APPROACH 1: Using Map (Hashing)
------------------------------------------------------------
Logic:
1. Create a map<int,int> to store frequency.
2. Traverse the array and increase frequency of each element.
3. Traverse the map:
      - If frequency == 1, that element occurs only once.

Time Complexity:
- Insertion in map takes O(log n)
- Loop runs n times
- Overall: O(n log n)

Space Complexity:
- O(n) (for storing elements in map)
============================================================
*/
int findUsingMap(vector<int> &v) {
    map<int, int> mp;

    // Counting frequency
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]]++;
    }

    // Finding element with frequency 1
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
        }
    }

    return -1; // if no unique element found
}

/*
============================================================
APPROACH 2: Using XOR (Bitwise)
------------------------------------------------------------
Logic:
1. XOR of same numbers becomes 0.
   Example:
   2 ^ 2 = 0
   5 ^ 5 = 0

2. XOR with 0 keeps number same:
   0 ^ x = x

3. So if every element appears twice except one,
   all duplicates cancel out and we get the unique element.

Time Complexity:
- Single loop → O(n)

Space Complexity:
- O(1) (No extra space used)
============================================================
*/
int findUsingXOR(vector<int> &v) {
    int xor1 = 0;

    for (int i = 0; i < v.size(); i++) {
        xor1 = xor1 ^ v[i];
    }

    return xor1;
}


/*
============================================================
SORTED ARRAY APPROACH (Linear Scan)
------------------------------------------------------------
Logic:
1. Traverse array with step of 2.
2. Since sorted:
      - If v[i] != v[i+1] → v[i] is unique.
      - Otherwise skip both.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/

int findUniqueSorted(vector<int> &v) {

    int n = v.size();

    for(int i = 0; i < n-1; i += 2) {

        if(v[i] != v[i+1]) {
            return v[i];
        }
    }

    // If unique element is last element
    return v[n-1];
}

int main() {

    vector<int> v = {1,1,2,2,3,3,4,4,5,6,6};

    int result1 = findUsingMap(v);
    cout << "Using Map Approach: " << result1 << endl;

    int result2 = findUsingXOR(v);
    cout << "Using XOR Approach: " << result2 << endl;

    return 0;
}
