#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 50;

    int left = 0,right = n;
    int ans  = -1;

    while(left<=right){
        int mid = (left+right)/2;
        int sqr = mid*mid;

        if(sqr> n){
            right = mid -1;
        }else{
          ans = mid;
          left = mid +1;
        }
    }

    cout<<ans<<" is the floor value of square root of the "<<n;

   return 0;
}
