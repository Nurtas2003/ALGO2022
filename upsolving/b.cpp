#include <bits/stdc++.h>
using namespace std;

void isValid(int n){
    bool isPrime[100000];

    for(int i=2; i<=n; i++){
        isPrime[i]=true;
    }

    isPrime[0] = isPrime[1] ==false;

    for(int i=2; i<=n; i++){
        int j=i+i;
        while(j<=n){
            isPrime[j]=false;
            j+=i;
        }
    }

    for(int i=2; i<=n; i++){
        for(int j=n; j>=2; j--){
            if(isPrime[i]==true && isPrime[j]==true){
                if(i+j==n){
                    cout << i  << " " << j << endl;
                    return;
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    isValid(n);
}