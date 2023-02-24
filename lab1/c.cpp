#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<char>st1, st2;
    string s, t;
    cin >> s >> t;
    string res1="", res2="";
    for(int i=0; i<s.size(); i++){
        if(s[i]!='#'){
            st1.push(s[i]);
        } else {
            st1.pop();
        }
    }
    for(int i=0; i<t.size(); i++){
        if(t[i]!='#'){
            st2.push(t[i]);
        } else {
            st2.pop();
        }
    }
    // cout << st1.top() << " " << st2.top() << endl;
    while(!st1.empty()){
        res1+=st1.top();
        st1.pop();
    }
    while(!st2.empty()){
        res2+=st2.top();
        st2.pop();
    }
    if(res1==res2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}