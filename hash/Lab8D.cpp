#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll p = 31;
ll MOD = 1e9 + 7;

ll p1 = 37;
ll MOD1 = 1e9 + 9;

long long occur[200005];
long long p_pows[200005];
long long p_pows1[200005];
long long hs[200005];
long long hs1[200005];
long long hhs[200005];
long long hhs1[200005];

int main() {

    p_pows[0] = 1;
    for (int i = 1; i < 100005; i++) {
        p_pows[i] = (p_pows[i - 1] * p) % MOD;
    }

    while(true){
        int q;
        cin >> q;
        if (q == 0) break;
        pair<string,int> str[q];
        for (int i = 0; i < q; i ++){
            cin >> str[i].first;
            str[i].second = 0;
        }
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            hs[i + 1] = (hs[i] + (s[i] - 'a' + 1) * p_pows[i]) % MOD;
        }
        int mx = -1;
        for (int i = 0; i < q; i ++){
            ll ht = 0;
            for (int j = 0; j < str[i].first.size(); j ++){
                ht = (ht + (str[i].first[j] - 'a' + 1) * p_pows[j]) % MOD;

            }
//            cout <<  ht << endl;

            for (int ii = 0; ii + str[i].first.size() - 1 < n; ii ++){
                ll cur = (hs[ii + str[i].first.size()] + MOD - hs[ii]) % MOD;
                if (ht * p_pows[ii] % MOD == cur){
                    str[i].second++;
                    mx = max(mx, str[i].second);
                }
            }
        }
        cout << mx << endl;
        for (int i = 0; i < q; i ++){
            if (str[i].second == mx){
                cout << str[i].first << endl;
            }
        }
    }
//    string s, s1;
//    cin >> s >> s1;
//    string str;
//    cin >> str;
//    int n = s.size();
//    int n1 = s1.size();
////    vector<long long> p_pows(s.size());
//    p_pows[0] = 1;
//    int n3 = str.size();
//    for (int i = 1; i < max(n3, max(n,n1)); i++) {
//        p_pows[i] = (p_pows[i - 1] * p) % MOD;
//    }
//
////    vector<long long> p_pows1(s.size());
//    p_pows1[0] = 1;
//    for (int i = 1; i < max(n3, max(n,n1)); i++) {
//        p_pows1[i] = (p_pows1[i - 1] * p1) % MOD1;
//    }
//
////    vector<ll> hs(n + 1, 0);
//    for (int i = 0; i < n; ++i) {
//        hs[i + 1] = (hs[i] + (s[i] - 'a' + 1) * p_pows[i]) % MOD;
//    }
//
////    vector<ll> hs1(n + 1, 0);
//    for (int i = 0; i < n; i ++){
//        hs1[i + 1] = (hs1[i] + (s[i] - 'a' + 1) * p_pows1[i]) % MOD1;
//    }
//
////    vector<ll> hhs(n1 + 1, 0);
//    for (int i = 0; i < n1; i ++){
//        hhs[i + 1] = (hhs[i] + (s1[i] - 'a' + 1) * p_pows[i]) % MOD;
//    }
//
////    vector<ll> hhs1(n1 + 1, 0);
//    for (int i = 0; i < n1; i ++){
//        hhs1[i + 1] = (hhs1[i] + (s1[i] - 'a' + 1) * p_pows1[i]) % MOD1;
//    }
//
//
//    ll ht = 0;
//    for (int i = 0; i < str.size(); i ++){
//        ht = (ht + (str[i] - 'a' + 1) * p_pows[i]) % MOD;
//    }
//
//    ll ht1 = 0;
//    for (int i = 0; i < str.size(); i ++){
//        ht1 = (ht1 + (str[i] - 'a' + 1) * p_pows1[i]) % MOD1;
//    }
//
////    cout << ht << " " << ht1 << endl;
//    long long ans = 0;
//    for (int i = 0; i + str.size() - 1 < n; i++) {
//        ll cur = (hs[i + str.size()] + MOD - hs[i]) % MOD;
//        ll cur1 = (hs1[i + str.size()] + MOD1 - hs1[i]) % MOD1;
//        if (ht * p_pows[i] % MOD == cur && ht1 * p_pows1[i] % MOD1 == cur1){
////            bool ok = true;
////            int k = 0;
////            int j = i;
////            while(k < str.size()){
//////                cout << s[j] << " " << str[k] << endl;
////                if (str[k] != s[j]){
////                    ok = false;
////                    break;
////                }
////                k++;j++;
////            }
////            cout << i << endl;
////            if (ok) occur[i]++;
//            occur[i]++;
//            if (occur[i] > 1) ans++;
//        }
//    }
////    cout << endl;
//    for (int i = 0; i + str.size() - 1 < n1; i ++){
//        ll cur = (hhs[i + str.size()] + MOD - hhs[i]) % MOD;
//        ll cur1 = (hhs1[i + str.size()] + MOD1 - hhs1[i]) % MOD1;
//        if (ht * p_pows[i] % MOD == cur && ht1 * p_pows1[i] % MOD1 == cur1){
////            bool ok = true;
////            int k = 0;
////            int j = i;
////            while(k < str.size()){
//////                cout << s1[j] << " " << str[k] << endl;
////                if (str[k] != s1[j]){
////                    ok = false;
////                    break;
////                }
////                k++;j++;
////            }
////            cout << i << endl;
////            if (ok) occur[i]++;
//            occur[i]++;
//            if (occur[i] > 1) ans++;
//        }
//    }
//
//    cout << ans << endl;
//    main();
}