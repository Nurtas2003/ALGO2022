#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    vector<int>sum(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sum[0]=a[0];

    for(int i=1; i<n; i++){
        sum[i]=a[i]+sum[i-1];
    }

    for(int i=0; i<m; i++){
        int x; cin >> x;
        int l=-1, r=n-1;
        while(l+1<r){
            int mid=(r+l)/2;
            if(sum[mid]>=x){
                r=mid;
            } else {
                l=mid;
            }
        }
        cout << r+1 << endl;
    }
}
