#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a){

    if(a <= 1) return false;

    for(int i = 2; i*i <= a; i++){
        if(a % i == 0){
            return false;
        }
    }

    return true;
}

int main(){

    int a;
    cin >> a;

    for(int i = 1; i*i <= a; i++){

        if(a % i == 0){

            if(isPrime(i))
                cout << i << " ";

            if(i != a/i && isPrime(a/i))
                cout << a/i << " t ";
        }
    }
}
