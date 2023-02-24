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
        // sift_up(size);
    }

    int sift_up(int i){
        while(i>1 && a[parent(i)]<a[i]){
            swap(a[parent(i)], a[i]);
            i=parent(i);
        }
        return i;
    }

    void sift_down(int i){
        int l=left(i);
        int r=right(i);
        int childMax=left(i);
        if(l>size) return;
        if(r<=size){
            if(a[r]>a[l]) childMax = r;
        }
        if(a[i] < a[childMax]){
            swap(a[i], a[childMax]);
            sift_down(childMax);
        }
    }

    int extractMax(){
        int ans = a[0];
        swap(a[0], a[size]);
        size--;
        sift_down(0);
        return ans;
    }

    void increase(int pos, int val){
        a[pos]+=val;
        sift_up(pos);
    }

    void decrease(int pos, int val){
        a[pos]-=val;
        sift_down(pos);
    }

    void change(int pos, int val){
        if(val>a[pos]){
            a[pos]=val;
            sift_up(pos);
        } else {
            a[pos]=val;
            sift_down(pos);
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void heap_build(){
        for(int i=size/2; i>=1; i--){
            sift_down(i);
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
    h.print();
    // h.change(4, 89);
    // h.print();
    // h.increase(2, 10);
    // h.decrease(3, 60);
    // h.print();
    // h.change(1, 5);
    // h.print();
    // h.change(1, 95);
    // h.print();
    // cout << h.extractMax() << endl;
    h.heap_build();
    h.print();
}