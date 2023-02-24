#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int NEW = 0;
int DURING =1;
int VISITED = 2;
vector<int> g[MAXN];
int used[MAXN];
vector<int> vv;

void dfs(int v){
    if(used[v]==DURING){
        cout << "Impossible" << endl;
        exit(0);
    }
    if(used[v]==VISITED) return;
    used[v]=DURING;
    // vv.push_back(v);
    for(int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    used[v] = VISITED;
    vv.push_back(v);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(used[i]==NEW){
            dfs(i);
        }
    }
    cout << "Possible" << endl;
    for(int i=vv.size()-1; i>=0; i--){
        cout << vv[i] << " ";
    }
    return 0;
}