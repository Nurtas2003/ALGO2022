#include <bits/stdc++.h>
using namespace std;

class Heap{
    int size;
    int a[100005];

public:
    Heap(){
        size=0;
        a[0]=INT_MAX;
    }

    int parent(int i){
        return i/2;
    }

    int left(int i){
        return i*2;
    }

    int right(int i){
        return i*2+1;
    }

    void insert(int val){
        size++;
        a[size]=val;
        sift_up(size);
    }

    int sift_up(int i){
        while(i>1 && a[parent(i)]<a[i]){
            swap(a[i], a[parent(i)]);
            i=parent(i);
        }
        return i;
    }

    void increase(int pos, int val){
        a[pos]+=val;
        cout << sift_up(pos) << endl;;
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << a[i] << " ";
        }
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
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int pos, val;
        cin >> pos >> val;
        h.increase(pos, val);
    }
    h.print();
}