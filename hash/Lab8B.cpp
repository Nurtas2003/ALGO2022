#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;
map <int, int> ma;
int ans = 0;

long long getHash(string & s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string & s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

void rabinKarp(string & s, string & t) {
    if (t.size() > s.size()) return;
    long long smallHash = getHash(t);
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += MOD;
        if (i != 0) smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif){
            if (ma.find(i) != ma.end()) {
//                cout << i << endl;
                ans++;
            }
            ma[i] = 1;
        }
    }

}

int main() {
    string s, t, str;
    cin >> s >> t >> str;
    rabinKarp(s, str);
    rabinKarp(t, str);
    cout << ans << endl;
}