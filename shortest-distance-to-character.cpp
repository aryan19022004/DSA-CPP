#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
     string s = "loveleetcode";
       char c = 'e';
       int n = s.size();
     vector<int> ans(n,0);
     int prev =  - n;
     for(int i =0;i<n;i++){
        if(s[i] == c){
            prev = i;
        }
        ans[i] = i - prev;
     }

     for(int i = n-1;i>=0;i-- ){
        if(s[i] == c){
            prev = i;
        }
        ans[i] = min(ans[i] , prev-i);
     }

     for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
     }
    return 0;
}
