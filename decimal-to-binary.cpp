#include <bits/stdc++.h>
using namespace std;



int main(){

    int a;
    cin >> a;
    string result = "";

    while(a>0){
       int remainder = a %2;
       a = a/2;
       result+=(remainder + '0');
    }
    reverse(result.begin(),result.end());



    cout<<result;



}
