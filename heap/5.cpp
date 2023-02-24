#include <bits/stdc++.h>
using namespace std;

class Heap{
    int size;
    int a[100005];

public:
    Heap(){
        size=0;
        a[0] = INT_MAX;
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

    void sift_up(int i){
        while(i>1 && a[parent(i)]<a[i]){
            swap(a[parent(i)], a[i]);
            i=parent(i);
        }
    }

    void sift_down(int i){
        int l=left(i);
        int r=right(i);
        int maxChild = left(i);
        if(l>size) return;
        if(r<=size){
            if(a[r]>a[l]) maxChild = r;
        }
        if(a[i]<a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
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
        }
        if(val<a[pos]){
            a[pos]=val;
            sift_down(pos);
        }
    }

    void build_heap(int val){
        for(int i=size/2; i>=1; i++){
            sift_down(i);
        }
    }

    void heapify(int i, int SZ){
        int l=left(i);
        int r=right(i);
        int maxChild = left(i);
        if(l>SZ) return;
        if(r<=SZ){
            if(a[r]>a[l]) maxChild = r;
        }
        if(a[i]<a[maxChild]){
            swap(a[i], a[maxChild]);
            heapify(maxChild, SZ);
        }
    }

    void heapSort(){
        for(int i=size; i>1; i--){
            swap(a[1], a[i]);
            heapify(1, i-1);
        }
    }

    int del(int i){
        int ans = a[0];
        swap(a[i], a[size]);
        size--;
        if(size>0){
            if(parent(i)>0 && a[parent(i)]<a[i]){
                sift_up(i);
            } else {
                sift_down(i);
            }
        }
        return ans;
    }

    void print(){
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
    cout << h.extractMax() << endl;
    h.print();
    h.increase(4, 35);
    h.print();
    h.decrease(3, 24);
    h.print();
    h.change(3, 100);
    h.print();
    h.heapSort();
    h.print();
    h.del(2);
    h.print();
}