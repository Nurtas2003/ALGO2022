#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, f;
    cin >> n >> f;
    long long a[n];
    for(long long i=0; i<n; i++){
        cin >> a[i];
    }
    long long l=1, r=0, m;
    for(long long i=0; i<n; i++){
        r=max(r, a[i]);
    }
    while(l<r){
        m=l+(r-l)/2;
        long long sum=0;
        for(long long i=0; i<n; i++){
            sum+=(a[i]+m-1)/m;
        }
        if(f>=sum){
            r=m;
        } else {
            l=m+1;
        }
    }
    cout << r << endl;
    return 0;
}