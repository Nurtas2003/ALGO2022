#include <bits/stdc++.h>
using namespace std;

void bin(string s){
    stack<char> st;
    for(long long i=0; i<s.size(); i++){
        if(!st.empty() && (st.top()=='1' && s[i]=='0')){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    if(st.empty()){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    long long n;
    cin >> n;
    for(long long i=0; i<n; i++){
        long long x; cin >> x;
        string b="";
        while(true){
            if(x==0) break;
            else if(x%2==0){
                x=x/2;
                b='0'+b;
            } else {
                x=x/2;
                b='1'+b;
            }
        }
        // string b;
        // cin >> b;
        bin(b);
    }
}