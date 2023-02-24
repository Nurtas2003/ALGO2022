#include <bits/stdc++.h>
using namespace std;
class Heap{
    int size;
    int a[100005];

public:
    Heap(){
        size=0;
        a[0]=999999;
    }

    int parent(int i){
        return i/2;
    }

    void insert(int x){
        size++;
        a[size]=x;
        sift_up(size);
    }

    void sift_up(int i){
        while(i>1 && a[parent(i)]<a[i]){
            swap(a[parent(i)], a[i]);
            i=parent(i);
        }
    }

    print(){
        for(int i=1; i<=size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Heap h;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        h.insert(x);
    }
    h.print();
}