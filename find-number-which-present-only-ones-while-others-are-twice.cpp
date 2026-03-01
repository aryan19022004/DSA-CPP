#include <iostream>
#include <vector>
#include <map>
using namespace std;

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

int main() {

    vector<int> v = {1,1,2,2,3,3,4,4,5,6,6};

    int result1 = findUsingMap(v);
    cout << "Using Map Approach: " << result1 << endl;

    int result2 = findUsingXOR(v);
    cout << "Using XOR Approach: " << result2 << endl;

    return 0;
}
