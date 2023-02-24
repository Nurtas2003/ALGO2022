#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    bool res=true;

    if(n==1){
        res=false;
    }
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
           res = false;
           break;
        }
    }
    return res;

}
int main(){
    int n;
    cin >> n;
    if(isPrime(n)){
        cout << "YES";
    } else {
        cout << "NO";
    }
}