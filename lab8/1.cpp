#include 
#include 
#define ll long long
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector p_pow(n);
    ll p = 5;
    p_pow[0] = 1; 
    for (int i = 1; i < n; ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }
    // for (int i = 0; i < n; ++i) {
    // cout << p_pow[i] << ' ';
    // }
    // cout << endl;
    ll ht = 0;
    for (int i = 0; i < t.size(); ++i) {
        ht += (t[i] - 'a' + 1) * p_pow[i]; // (t[i] - 96) chtoby a = 1, b = 2, c = 3...
    }
    // cout << ht << endl;
    /*
    ababbababa
    aba
    1 5 25 125 625 3125 15625 78125 390625 1953125 
    36
    */
    // ababbababa
    // hs[] = [h(a), h(ab), h(aba), h(abab), h(ababb), ...]
    // 1 11 36 286 1536 4661
    vector hs(n);
    for (int i = 0; i < n; ++i) {
        // hs[i] = (s[i] - 96) * p_pow[i]
        hs[i] = (s[i] - 96) * p_pow[i];
        if (i > 0) hs[i] += hs[i - 1];
    }
    // for (auto i : hs) {
    // cout << i << ' ';
    // }
    // cout << endl;
    /*
    ababbababa
    aba
    1 5 25 125 625 3125 15625 78125 390625 1953125 
    36
    1 11 36 286 1536 4661 35911 114036 895286 2848411 
    */
    for (int i = 0; i + t.size() - 1 < n; i++) {
        ll cur = hs[i + t.size() - 1];
        if (i > 0) cur -= hs[i - 1];
        if (ht * p_pow[i] == cur) cout << i << ' ';
    }
    // i = 0 --> h[0 + 3 - 1] --> h[2]
    // i = 1 --> h[1 + 3 - 1] --> h[3]
    return 0;
} 