#include<bits/stdc++.h>
using namespace std;

int main(){
int num= 30;
string result = "";
  while(num>0){
    num--;
    int rem = num%26;
    char c = 'A' + rem;
    result +=c;
    num = num/26;
    
  }
  reverse(result.begin(),result.end());
  cout<<result;
}

