#include <bits/stdc++.h>
using namespace std;

int c[1000008];

void Merge(int a[], int b[], int n, int m){
    int i, j, k;
    i=j=k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++; i++;
        } else {
            c[k]=b[j];
            k++; j++;
        }
    }

    for(; i<n; i++){
        c[k]=a[i];
        k++;
    }

    for(; j<m; j++){
        c[k]=b[j];
        k++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int j=0; j<m; j++){
        cin >> b[j];
    }

    Merge(a, b, n, m);

    for(int i=0; i<n+m; i++){
        cout << c[i] << " ";
    }
}