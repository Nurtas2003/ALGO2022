#include <bits/stdc++.h>
using namespace std;

class Heap{
    int size;
    int a[1000005];
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

    void sift_up(int i){
        while(i<1 && a[parent(i)]<a[i]){
            swap(a[i], a[parent(i)]);
            i=parent(i);
        }
    }

    void sift_down(int i){
        int l= left(i);
        int r=right(i);
        int max=left(i);
        if(l>size) return;
        if(r<=size){
            if(a[r]>a[l]) max=r;
        }
        if(a[i]<a[max]){
            swap(a[i], a[max]);
            sift_down(max);
        }
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
        } else if(val<a[pos]){
            a[pos]=val;
            sift_down(pos);
        }
    }

    int ExtractMax(){
        int ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    void heapSort(){
        for(int i=size; i>1; i--){
            swap(a[1], a[i]);
            heapify(1, i-1);
        }
    }

    void heapify(int val, int SZ){
        int l= left(i);
        int r=right(i);
        int max=left(i);
        if(l>SZ) return;
        if(r<=SZ){
            if(a[r]>a[l]) max=r;
        }
        if(a[i]<a[max]){
            swap(a[i], a[max]);
            sift_down(max, SZ);
        }
    }

    void print(){
        for(int i=1; i<size; i++){
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
    cout << h.ExtractMax() << endl;
    h.print();
}