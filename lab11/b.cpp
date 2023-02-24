#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<pair<int, int>>g[maxn];
bool used[maxn];

int main(){
    int n;
    cin >> n;
    int a[505];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        g[0].push_back({i, a[i]+a[0]});
        g[i].push_back({0, a[i]+a[0]});
    }
    int cnt=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
    q.push({0, 1});

    while(!q.empty()){
        pair<int, int> pa=q.top();
        q.pop();

        int mst = pa.first, v=pa.second;
        if(used[v]) continue;

        used[v]=true;
        cnt+=mst;

        for(pair<int, int> i : g[v]){
            int u = i.first, l=i.second;
            if(!used[u]){
                q.push({l, u});
            }
        }
    }
    cout << cnt << endl;
}