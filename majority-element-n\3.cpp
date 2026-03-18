#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 🔴 1. BRUTE FORCE APPROACH
// ============================================================
vector<int> bruteForce(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;

    for(int i = 0; i < n; i++) {
        int count = 0;

        // count frequency of nums[i]
        for(int j = 0; j < n; j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
        }

        // check if > n/3
        if(count > n/3) {
            // avoid duplicates
            bool already = false;
            for(auto x : result) {
                if(x == nums[i]) {
                    already = true;
                    break;
                }
            }
            if(!already) result.push_back(nums[i]);
        }
    }

    return result;

    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
}


// ============================================================
// 🟡 2. BETTER APPROACH (Using HashMap)
// ============================================================
vector<int> better(vector<int>& nums) {
    int n = nums.size();
    map<int,int> freq;
    vector<int> result;

    // store frequency
    for(auto num : nums) {
        freq[num]++;
    }

    // check majority
    for(auto it : freq) {
        if(it.second > n/3) {
            result.push_back(it.first);
        }
    }

    return result;

    // Time Complexity: O(n)
    // Space Complexity: O(n)
}


// ============================================================
// 🟢 3. OPTIMAL APPROACH (Moore Voting Algorithm)
// ============================================================
vector<int> optimal(vector<int>& nums) {
    int n = nums.size();

    int candidate1 = -1, candidate2 = -1;
    int count1 = 0, count2 = 0;

    // Step 1: Find candidates
    for(auto num : nums) {
        if(num == candidate1) {
            count1++;
        }
        else if(num == candidate2) {
            count2++;
        }
        else if(count1 == 0) {
            candidate1 = num;
            count1 = 1;
        }
        else if(count2 == 0) {
            candidate2 = num;
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify candidates
    count1 = 0;
    count2 = 0;

    for(auto num : nums) {
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
    }

    vector<int> result;

    if(count1 > n/3) result.push_back(candidate1);
    if(count2 > n/3) result.push_back(candidate2);

    return result;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}


// ============================================================
// 🚀 MAIN FUNCTION
// ============================================================
int main() {

    vector<int> nums = {1,2,3,1,1,2,2};

    vector<int> ans1 = bruteForce(nums);
    vector<int> ans2 = better(nums);
    vector<int> ans3 = optimal(nums);

    cout << "Brute Force: ";
    for(auto x : ans1) cout << x << " ";
    cout << endl;

    cout << "Better: ";
    for(auto x : ans2) cout << x << " ";
    cout << endl;

    cout << "Optimal: ";
    for(auto x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}
