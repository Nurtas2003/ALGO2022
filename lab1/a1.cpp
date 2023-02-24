#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n>0){
        int m;
        cin >> m;
        n--;
        deque<int>q1, q2;
        vector<int> v(1001);
        for(int i=m; i>0; i--){
            q1.push_back(m);
        }
        int i=m;
        while(!q1.empty()){
            int j=0;
            while(j<i){
                int x=q1.front();
                q1.pop_front();
                q1.push_back(x);
                j++;
            }
            int x=q1.front();
            if(v[x]!=0){
                cout << -1 << endl;
                return 0;
            }
            v[x]=i;
            q1.pop_front();
            i--;
        }
        for(int i=1; i<=m; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}