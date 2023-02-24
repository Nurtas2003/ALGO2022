#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<int> v1, v2;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v1.push_back(x);

    }
    sort(v1.begin(), v1.end());

    for(int i=0; i<v1.size(); i++){
        int target=m-v1[i];        
        int l=i+1, r=v1.size()-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(v1[mid]==target){ 
                cout << v1[i] << " " <<v1[mid];
                return 0;
            }
            else if(v1[mid]>target) {
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
    }
}