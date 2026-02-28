#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
=========================================================
1️⃣ BRUTE FORCE APPROACH (Using Extra Vectors)

Logic:
- First k elements ko alag vector me store karo
- Remaining elements ko alag vector me store karo
- Pehle remaining elements result me daalo
- Fir first k elements result me daalo

Time Complexity:
O(n)  (3 passes over array)

Space Complexity:
O(n)  (extra vectors used)

Order Preserved: YES
=========================================================
*/

void leftRotateBruteForce(vector<int> v, int k) {

    int n = v.size();
    k = k % n;  // handle k > n

    vector<int> firstPart;
    vector<int> secondPart;
    vector<int> result;

    // Store first k elements
    for(int i = 0; i < k; i++) {
        firstPart.push_back(v[i]);
    }

    // Store remaining elements
    for(int i = k; i < n; i++) {
        secondPart.push_back(v[i]);
    }

    // Add remaining first
    for(int i = 0; i < secondPart.size(); i++) {
        result.push_back(secondPart[i]);
    }

    // Add first k elements
    for(int i = 0; i < firstPart.size(); i++) {
        result.push_back(firstPart[i]);
    }

    cout << "Brute Force Rotation: ";
    for(auto it : result) {
        cout << it << " ";
    }
    cout << endl;
}


/*
=========================================================
2️⃣ OPTIMIZED APPROACH (Reversal Algorithm)

Logic:
- Reverse first k elements
- Reverse remaining n-k elements
- Reverse whole vector

Time Complexity:
O(n)

Space Complexity:
O(1)  ⭐ (No extra space used)

Order Preserved: YES
=========================================================
*/

void leftRotateOptimized(vector<int>& v, int k) {

    int n = v.size();
    k = k % n;  // handle k > n

    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    reverse(v.begin(), v.end());

    cout << "Optimized Rotation: ";
    for(auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}


/*
============================ MAIN ============================
*/

int main() {

    vector<int> v = {1,1,1,2,2,2,3,4,5,6,6,7,7};
    int k = 4;

    leftRotateBruteForce(v, k);

    leftRotateOptimized(v, k);

    return 0;
}
