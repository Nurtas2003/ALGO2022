#include <bits/stdc++.h>
using namespace std;

int c[1000008];

void MergeOne(int a[], int l, int mid, int r){
    int i, j, k;
    i=l;
    j=mid+1;
    k=l;
    int b[r+1];
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k]=a[i];
            k++; i++;
        } else {
            b[k]=a[j];
            k++; j++;
        }
    }
    for(; i<=mid; i++){
        b[k]=a[i];
        k++;
    }

    for(; j<=r; j++){
        b[k]=a[j];
        k++;
    }

    for(i=l; i<=r; i++){
        a[i]=b[i];
    }

}

void MergeTwo(int a[], int b[], int n, int m){
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

void MergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        MergeOne(a, l, m, r);
    }
}

int main(){
    int a[8]={1, 2, 11, 4, 6, 8, 15, 22};
    MergeOne(a, 0, 2, 7);
    for(int i=0; i<8; i++){
        cout << a[i] << " ";
    }
    // int n, m;
    // cin >> n >> m;
    // int a[n], b[m];
    // for(int i=0; i<n; i++){
    //     cin >> a[i];
    // }

    // for(int j=0; j<m; j++){
    //     cin >> b[j];
    // }

    // MergeTwo(a, b, n, m);

    // for(int i=0; i<n+m; i++){
    //     cout << c[i] << " ";
    // }
}