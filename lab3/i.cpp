#include <bits/stdc++.h>
using namespace std;

bool binRecurs(int a[], int x, int l, int r){
    if(l>r) return false;
    int mid = l+((r-l)/2);
    if(a[mid]==x) return true;
    else if(x<a[mid]) return binRecurs(a, x, l, mid-1);
    else return binRecurs(a, x, mid+1, r);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    if(binRecurs(a, x, 0, n-1)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}