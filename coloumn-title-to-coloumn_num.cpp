#include<bits/stdc++.h>
using namespace std;

int main(){
 string title = "AB";
  int result = 0;
  for(char c : title){
    int num = c - 'A' + 1;
    result = result*26 + num;
  }
  cout<<result;
  return 0;
}
