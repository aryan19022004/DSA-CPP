#include <iostream>
#include <vector>
using namespace std;

/*
----------------------------------------------------
APPROACH 1 : Using Two Extra Arrays (Better)
----------------------------------------------------

Logic:
1. Traverse the original array.
2. Store positive numbers in arr_positive.
3. Store negative numbers in arr_negative.
4. Fill the original array alternatively:
   - Even index -> positive
   - Odd index -> negative

Time Complexity: O(n)
(One loop for separation + one loop for rearranging)

Space Complexity: O(n)
(Two extra arrays are used)
*/

void rearrangeUsingTwoArrays(vector<int> arr){

    int n = arr.size();

    vector<int> arr_positive;
    vector<int> arr_negative;

    // Separate positive and negative numbers
    for(auto it : arr){
        if(it < 0){
            arr_negative.push_back(it);
        }else{
            arr_positive.push_back(it);
        }
    }

    int pos = 0;
    int neg = 0;

    // Rearranging alternatively
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            arr[i] = arr_positive[pos];
            pos++;
        }else{
            arr[i] = arr_negative[neg];
            neg++;
        }
    }

    cout << "Approach 1 Output: ";
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}



/*
----------------------------------------------------
APPROACH 2 : Direct Placement Using Index Jump
----------------------------------------------------

Logic:
1. Create a result array of same size.
2. Maintain two pointers:
   - posIndex = 0  (for positive numbers)
   - negIndex = 1  (for negative numbers)
3. Traverse the original array:
   - If element is positive → place at posIndex and move posIndex by +2
   - If element is negative → place at negIndex and move negIndex by +2

Time Complexity: O(n)
(Only one traversal of array)

Space Complexity: O(n)
(One extra result array)
*/

void rearrangeUsingIndexPlacement(vector<int> arr){

    int n = arr.size();
    vector<int> ans(n);

    int posIndex = 0;
    int negIndex = 1;

    for(int i = 0; i < n; i++){

        if(arr[i] > 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }

    }

    cout << "Approach 2 Output: ";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}



int main() {

    vector<int> arr = {3,1,-2,-5,2,-4};

    rearrangeUsingTwoArrays(arr);
    rearrangeUsingIndexPlacement(arr);

    return 0;
}
