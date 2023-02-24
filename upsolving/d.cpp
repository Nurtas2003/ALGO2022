#include <bits/stdc++.h>
using namespace std;

void isValid(long long n){
    long long cnt=0;
    for(int i=2; i<=n; i++){
        if(n%i==0){
            cnt++;
            while(n%i==0){
                n/=i;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    long long n;
    cin >> n;
    isValid(n);
}