#include <iostream>
#include <vector>
using namespace std;

/*
=========================================================
1️⃣ BRUTE FORCE APPROACH
---------------------------------------------------------
Logic:
- Ek naya vector banao.
- Pehle saare non-zero elements usme daal do.
- Count karo kitne zeros the.
- End me utne zeros push_back kar do.

Time Complexity:
O(n)  (single traversal)

Space Complexity:
O(n)  (extra vector used)

Order Preserved: YES
=========================================================
*/

void moveZerosBruteForce(vector<int> v) {

    int n = v.size();
    vector<int> temp;

    int zeroCount = 0;

    // Store non-zero elements
    for(int i = 0; i < n; i++) {
        if(v[i] != 0) {
            temp.push_back(v[i]);
        } else {
            zeroCount++;
        }
    }

    // Add zeros at end
    for(int i = 0; i < zeroCount; i++) {
        temp.push_back(0);
    }

    cout << "Brute Force: ";
    for(auto it : temp) {
        cout << it << " ";
    }
    cout << endl;
}



/*
=========================================================
2️⃣ OPTIMAL APPROACH (Two Pointer Method)
---------------------------------------------------------
Logic:
- j pointer maintain karega next position for non-zero.
- i pointer pura array traverse karega.
- Jab non-zero mile:
      swap(v[i], v[j])
      j++

Isse:
- Non-zero elements front me aa jaate hain
- Zeros automatically end me shift ho jaate hain

Time Complexity:
O(n)

Space Complexity:
O(1)  ⭐ (In-place, no extra memory)

Order Preserved: YES
=========================================================
*/

void moveZerosOptimal(vector<int> v) {

    int n = v.size();
    int j = 0;   // position for next non-zero

    for(int i = 0; i < n; i++) {
        if(v[i] != 0) {
            swap(v[i], v[j]);
            j++;
        }
    }

    cout << "Optimal: ";
    for(auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}



/*
=========================== MAIN ===========================
*/

int main() {

    vector<int> v = {1,0,0,2,3,0,4,0,0,0,6};

    moveZerosBruteForce(v);
    moveZerosOptimal(v);

    return 0;
}
