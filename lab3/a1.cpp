#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int b[t];
    for(int i=0; i<t; i++){
        cin >> b[i];
    }
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<t; i++){
        int x = b[i];
        int li=0, ri=n;
        while(li+1<ri){
            int mid = (li+ri)/2;
            int num;
            if(mid%2==0){
                num = a[mid][0];
            } else {
                num = a[mid][m-1];
            }

            if(num>=x){
                li = mid;
            } else {
                ri = mid;
            }
        }
        if(li%2==0){
            bool ok = false;
            int l = 0, r = m-1;
            while(l<=r){
                int mid = (l+(r-l))/2;
                if(a[li][mid]==x){
                    cout << li << " " << mid << endl;
                    ok=true;
                    break;
                } else if(a[li][mid]>x){
                    r=mid-1;
                } else if(a[li][mid]<x){
                    l=mid+1;
                } 
            }
            if(ok==false){
                cout << -1 << endl;
            }
        } else {
            bool ok = false;
            int l = 0, r = m-1;
            while(l<=r){
                int mid = (l+(r-l))/2;
                if(a[li][mid]==x){
                    cout << li << " " << mid << endl;
                    ok=true;
                    break;
                } else if(a[li][mid]>x){
                    l=mid-1;
                } else if(a[li][mid]<x){
                    r=mid+1;
                } 
            }
            if(ok==false){
                cout << -1 << endl;
            }
        }
    }
}