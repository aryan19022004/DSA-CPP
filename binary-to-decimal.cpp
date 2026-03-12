#include <bits/stdc++.h>
using namespace std;



int main(){

    int a,result = 0;;
    cin >> a;
    int index = 0;

    while(a>0){
        int digit = a%10;
        if(digit == 1){
            result += pow(2,index) * digit;
        }
        a = a/10;
        index++;

    }

    cout<<result<<" is the corresponding  Decimal number ";




}
