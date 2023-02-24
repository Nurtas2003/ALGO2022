#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<long long>q;
    long long n;
    cin >> n;
    for(long long i=0; i<n; i++){
        long long x; cin >> x;
        q.push_back(x);
        while(!q.empty() && q.front()<x-3000){
            q.pop_front();
        }
        // return q.size();
        cout << q.size() << " ";
    }
}