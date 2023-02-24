#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<long long>p_pow(n);
    long long p=5;
    p_pow[0]=1;
    for(int i=1; i<n; i++){
        p_pow[i]=p_pow[i-1]*p;
    }

    for(int i=0; i<n; i++){
        cout << p_pow[i] << " ";
    }
    cout << endl;

    long long ht=0;
    for(int i=0; i<t.size(); i++){
        ht+=(t[i]-'a'+1)*p_pow[i];
    }
    cout << ht << endl;

    vector<long long>hs(n);
    for(int i=0; i<n; i++){
        hs[i]=(s[i]-'a'+1)*p_pow[i];
        if(i>0) hs[i]+=hs[i-1];
    }

    for(long long i=0; i<hs.size(); i++){
        cout << hs[i] << " ";
    }
    cout << endl;
}