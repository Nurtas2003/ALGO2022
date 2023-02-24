#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    queue<int>q;
    bool isPrime[1000000];

    for(int i=2; i<=n*n; i++){
        isPrime[i] = true;
    }
    if(n==1){
        cout << 2 << " ";
    }

    isPrime[0] = isPrime[1] == false;
    
    for(int i=2; i<=n*n; i++){
        if(isPrime[i] == true){
            int j=i+i;
            while(j<=n*n){
                isPrime[j]=false;
                j+=i;
            }
        }
    }

    for(int i=2; i<=n*n; i++){
        if(isPrime[i]){
            q.push(i);
        }
    }
    int i=1;
    while(!q.empty()){
        if(n==i){
            cout << q.front() << endl;
        }
        q.pop();
        i++;
    }
    return 0;
}