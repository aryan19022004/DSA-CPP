// Program to find all missing numbers in a sorted array
// Example: {1,2,5,6,11} → Missing numbers: 3 4 7 8 9 10

#include <iostream>
#include <vector>
using namespace std;

int main() {

   // Input sorted array
   vector<int> v = {1,2,5,6,11};
   
   // Vector to store missing numbers
   vector<int> v2;

   int n = v.size();

   /*
   ---------------------------------------------------------
   LOGIC:
   ---------------------------------------------------------
   1. Traverse the array from index 1 to n-1.
   2. Find the difference between current and previous element.
   3. If difference > 1, then numbers are missing in between.
   4. Push all numbers between v[i-1] and v[i] into v2.
   ---------------------------------------------------------
   */

   for(int i = 1; i < n; i++){
       
       int diff = v[i] - v[i-1];

       // If gap is more than 1, numbers are missing
       if(diff > 1){
           for(int j = v[i-1] + 1; j < v[i]; j++){
               v2.push_back(j);
           }
       }
   }

   cout << "Following numbers are missing in the Array\n";
   for(auto it : v2){
       cout << it << " ";
   }

   return 0;
}

/*
---------------------------------------------------------
TIME COMPLEXITY:
---------------------------------------------------------
Outer loop runs → O(n)
Inner loop runs only for missing numbers.

Total Time Complexity = O(n + m)
Where:
n = size of array
m = number of missing elements

Since we must print all missing numbers,
this is already optimal.

---------------------------------------------------------
SPACE COMPLEXITY:
---------------------------------------------------------
O(m)
Because we are storing missing elements
in a separate vector.

If we directly print instead of storing,
space complexity becomes O(1).
---------------------------------------------------------
*/
