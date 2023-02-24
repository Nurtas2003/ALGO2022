#include <bits/stdc++.h>
using namespace std;

struct Stack {

    int r;
    int a[100000];

    Stack(){
        r=0; 
    }

    void push(int x){
        a[r]=x;
        r++;
    }
    void maxi(){
        int max=-1;
        for(int i=0; i<r; i++){
            if(max<a[i]){
                max=a[i];
            }
        }
        cout << max << endl;
    }

    void pop(){
        r--;
    }
    int top(){
        return a[r-1];
    }
    int size(){
        return r;
    }
    bool empty(){
        return r==0;
    }
};

int main(){
    Stack st;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s=="add"){
            int n; cin >> n;
            st.push(n);
        } else if(s=="delete"){
            st.pop();
        } else if(s=="getcur"){
            if(st.empty()){
                cout << "error" << endl;
            } else {
                cout << st.top() << endl;
            }
        } else if(s=="getmax"){
            if(st.empty()){
                cout << "error" << endl;
            } else {
                st.maxi();
            }
        }
    }
}