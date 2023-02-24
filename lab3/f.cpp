#include <bits/stdc++.h>
using namespace std;

int bin(vector<int> num, int x){
    if(x<num[0]){
        return -1;
    }
    int l = 0, r = num.size();
    while(l+1<r){
        int mid = (l+r)/2;
        if(num[mid]<=x){
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    vector<int> num;
    vector<int> sum(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        num.push_back(a[i]);
    }

    sort(num.begin(), num.end());
    // for(int i=0; i<num.size(); i++){
    //     cout << num[i] << " ";
    // }
    sum[0]=num[0];
    for(int i = 1; i < n; i++){
        sum[i] = num[i] + sum[i-1];
    }

    int k;
    cin >> k;
    while(k--){
        int x;
        cin >> x;
        int res = bin(num, x);
        cout << (res!=-1 ? res+1 : 0) << " " << (res!=-1 ? sum[res] : 0) << endl;
    }
}