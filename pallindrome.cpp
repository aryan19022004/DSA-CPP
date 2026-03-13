#include <bits/stdc++.h>
using namespace std;



int main(){

string name = "MADAM";
int left = 0,right = name.length()-1;

while(left<right){
    if(name[left]!=name[right]){
        cout<<"This string is not pallindrome";
        return 0;
    }
    left++;
    right--;
}

cout<<"This string is the pallindrome";
return 0;

}
