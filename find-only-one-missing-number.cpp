// Program to find the missing number from 1 to n
// Example: {1,2,3,4,6} and n = 6 → Missing number = 5

#include <iostream>
#include <vector>
using namespace std;

int main() {

   // Given sorted array containing numbers from 1 to n
   // with exactly one number missing
   vector<int> v = {1,2,3,4,6};
   int n = 6;   // Range is from 1 to n

   /*
   ---------------------------------------------------------
   LOGIC:
   ---------------------------------------------------------
   1. Calculate the sum of elements present in the array.
   2. Calculate the expected sum of first n natural numbers
      using formula: n(n+1)/2.
   3. The difference between expected sum and actual sum
      will give the missing number.
   ---------------------------------------------------------
   */

   // Step 1: Calculate actual sum of array elements
   int sum = 0;
   for(int i = 0; i < v.size(); i++){
       sum = sum + v[i];
   }

   // Step 2: Calculate expected sum from 1 to n
   int needed_sum = n * (n + 1) / 2;

   // Step 3: Missing number
   int missing_number = needed_sum - sum;

   cout << "The missing number is " << missing_number;

   return 0;
}

/*
---------------------------------------------------------
TIME COMPLEXITY:
---------------------------------------------------------
O(n)
Because we traverse the array once to calculate the sum.

---------------------------------------------------------
SPACE COMPLEXITY:
---------------------------------------------------------
O(1)
We are not using any extra data structure.
Only a few integer variables are used.

---------------------------------------------------------
NOTE:
---------------------------------------------------------
This approach works only when:
- Numbers are from 1 to n
- Exactly one number is missing
- No duplicates are present
---------------------------------------------------------

// ---------------------------------------------------------
// Alternative Approach: Using XOR to Find Missing Number
// Example: {1,2,3,4,6} and n = 6 → Missing number = 5
// ---------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Given array containing numbers from 1 to n
    // with exactly one number missing
    vector<int> v = {1,2,3,4,6};
    int n = 6;

    /*
    ---------------------------------------------------------
    LOGIC:
    ---------------------------------------------------------
    XOR Properties Used:
    1. a ^ a = 0
    2. a ^ 0 = a
    3. XOR is commutative and associative

    Steps:
    1. Take XOR of all numbers from 1 to n → xor1
    2. Take XOR of all elements present in array → xor2
    3. XOR both results → xor1 ^ xor2
    4. Duplicate numbers cancel out automatically.
       The remaining value will be the missing number.
    ---------------------------------------------------------
    */

    int xor1 = 0; // XOR of numbers from 1 to n
    int xor2 = 0; // XOR of elements in array

    // Step 1: XOR of 1 to n
    for(int i = 1; i <= n; i++)
        xor1 ^= i;

    // Step 2: XOR of array elements
    for(int i = 0; i < v.size(); i++)
        xor2 ^= v[i];

    // Step 3: Missing number
    int missing = xor1 ^ xor2;

    cout << "Missing number is " << missing;

    return 0;
}

/*
---------------------------------------------------------
TIME COMPLEXITY:
---------------------------------------------------------
O(n)
We traverse the range 1 to n once
and the array once.

---------------------------------------------------------
SPACE COMPLEXITY:
---------------------------------------------------------
O(1)
Only a few integer variables are used.
No extra data structure is required.

---------------------------------------------------------
ADVANTAGE OVER SUM METHOD:
---------------------------------------------------------
- No integer overflow risk (important for large n).
- Efficient and clean bit manipulation approach.

---------------------------------------------------------
LIMITATION:
---------------------------------------------------------
- Works only when:
  • Numbers are from 1 to n
  • Exactly one number is missing
  • No extra duplicate elements are present
---------------------------------------------------------
*/
*/
