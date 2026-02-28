#include <iostream>
#include <vector>
using namespace std;

/*
-----------------------------------------
Left Rotate by 1

Time Complexity: O(n)
Space Complexity: O(1)

Logic:
- Store first element
- Shift all elements left
- Put first element at end
-----------------------------------------
*/

int main() {

    vector<int> v = {1,1,1,2,2,2,3,4,5,6,6,7,7};

    int n = v.size();
    int first = v[0];

    for(int i = 1; i < n; i++) {
        v[i-1] = v[i];
    }

    v[n-1] = first;

    for(auto it : v) {
        cout << it << " ";
    }

    return 0;
}
