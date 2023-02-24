#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<pair<int, int>>g[maxn];
bool used[maxn];

int main(){
    int n,m; cin >> n >> m;
    int x,y; cin >> x >> y;
    for(int i = 1;i <= m;i++){
        string s; cin >>s;
        int a,b,c; cin >> a >> b >> c;
        if(s == "big"){
            g[a].push_back({b, c*x});
            g[b].push_back({a, c*x});
        }else if(s == "small"){
            g[a].push_back({b, c*y});
            g[b].push_back({a, c*y});
        }else if(s == "both"){
            g[a].push_back({b, c* min(x,y)});
            g[b].push_back({a, c* min(x,y)});
        }
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