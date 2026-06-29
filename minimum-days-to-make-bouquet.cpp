#include <bits/stdc++.h>
using namespace std;

class GardenFlowers
{
public:
    bool isPossible(vector<int>&nums,int day,int m,int k)
    {
        int count = 0;
        int bouquet = 0;

        for(int num : nums)
        {
            if(num<=day)
            {
                count++;
                if(count == k)
                {
                    bouquet++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }

        return bouquet >=m;
    }


    int minimumDays(vector<int>&nums,int m, int k)
    {
        long long totalFlowers = 1LL * m * k;
        int ans = -1;
        if(totalFlowers > nums.size())
        {
            return -1;
        }

        int high = *max_element(nums.begin(),nums.end());
        int low = *min_element(nums.begin(),nums.end());

        while(low<=high)
        {
            int mid = (high + low)/2;

            if(isPossible(nums,mid,m,k))
            {
                ans = mid;
                high = mid -1;

            }
            else
            {

                low = mid +1;
            }
        }

        return ans;
    }
};



int main()
{
    vector<int> nums = {7,7,7,7,13,11,12,7};
    int m = 2,k = 3;
    GardenFlowers garden;

    int minday = garden.minimumDays(nums,m,k);

    cout<<minday;



    return 0;
}
