#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s=="add"){
            int n; cin >> n;
            st.push(n);