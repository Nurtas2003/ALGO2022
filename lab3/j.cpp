#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];

bool shop(int x){
    int sum=0;
    double l;
    for(int i=0; i<n; i++){
        l=a[i];
        l=l/x;
        sum+=ceil(l);
    }
    return sum<=k;
}

int bs(int max){
    int l=0, r=max, m;
    while(true){
        m=l+(r-l)/2;
        if(shop(m)){
            r=m;
        } else {
            l=m;
        }
        if(r-l==1){
            return r;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int max=a[0];
    cout << bs(10000001);
}