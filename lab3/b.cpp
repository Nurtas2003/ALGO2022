#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long l, r;
    l=0; r=1e15;
    long long sum, cnt, m;
    while(l<=r){
        m=l+(r-l)/2;
        cnt=1;
        sum=0;
        for(int i=0; i<n; i++){
            if(m<sum+a[i]){
                sum=0;
                cnt++;
            }
            if(m<a[i]){
                cnt=k+1;
            }
            sum+=a[i];
        }
        if(k<cnt){
            l=m+1; 
        } else {
            r=m-1;
        }
    }
    cout << l << endl;
    return 0;
}