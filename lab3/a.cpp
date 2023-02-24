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

        int lj = 0, rj = m;
        if(li%2==0){
            while(lj+1<rj){
                int mid = (lj+rj)/2;
                int num = a[li][mid];
                if(num>=x){
                    lj=mid;
                } else {
                    rj = mid;
                }
            }
        } else {
            while(lj+1<rj){
                int mid = (lj+rj)/2;
                int num = a[li][mid];
                if(num<=x){
                    lj=mid;
                } else {
                    rj = mid;
                }
            }
        }
        int res = a[li][lj];
        if(res==x){
            cout << li << " " << lj << endl;
        } else {
            cout << -1 << endl;
        }
    }
}