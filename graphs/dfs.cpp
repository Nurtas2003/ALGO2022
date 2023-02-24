#include <bits/stdc++.h>
using namespace std;

const int Maxn=1005;
vector<int> g[Maxn];
bool used[Maxn];

void dfs(int v){
    used[v]=true;
    for(int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]){
            dfs(to);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!used[i]){
            dfs(i);
        }
    }
}