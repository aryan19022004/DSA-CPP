// ---------------------------------------------------------
// Program: Find Maximum Consecutive 1's in an Array
// Example: {1,1,1,1,0,1,1,1,1,1,1,0,1,1}
// Output: Maximum number of consecutive 1's
// ---------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {

   // Input binary array (contains only 0 and 1)
   vector<int> v = {1,1,1,1,0,1,1,1,1,1,1,0,1,1};
   
   int n = v.size();

   int count = 0;      // To count current consecutive 1's
   int max_count = 0;  // To store maximum consecutive 1's found so far

   /*
   ---------------------------------------------------------
   LOGIC:
   ---------------------------------------------------------
   1. Traverse the array from index 0 to n-1.
   2. If current element is 1:
        - Increment count.
   3. If current element is 0:
        - Update max_count with max(max_count, count).
        - Reset count to 0.
   4. After loop ends, update max_count again
      (important in case array ends with 1's).
   ---------------------------------------------------------
   */

   for(int i = 0; i < n; i++){
       if(v[i] == 1){
           count++;   // Increase streak of 1's
       }
       else{
           max_count = max(max_count, count);  // Update max
           count = 0;  // Reset streak
       }
   }

   // Final update (handles case where array ends with 1's)
   max_count = max(max_count, count);

   cout << "Maximum number of 1's is " << max_count;

   return 0;
}

/*
---------------------------------------------------------
TIME COMPLEXITY:
---------------------------------------------------------
O(n)
We traverse the array once.

---------------------------------------------------------
SPACE COMPLEXITY:
---------------------------------------------------------
O(1)
Only two integer variables are used.
No extra data structure is required.

---------------------------------------------------------
WHY FINAL UPDATE IS IMPORTANT?
---------------------------------------------------------
If the array ends with consecutive 1's,
the loop will not enter the 'else' block,
so we must update max_count after loop.
---------------------------------------------------------
*/
