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
            swap(a[parent(i)], a[i]);
            i=parent(i);
        }
        return i;
    }

    int extractMax(){
        int ans = a[0];
        swap(a[0], a[size]);
        size--;
        sift_down(0);
        return ans;
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild=left(i);
        if(l>size) return;
        if(r<=size){
            if(a[r]>a[l]) maxChild = r;
        }
        if(a[i]<a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
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
            cout << sift_up(pos) << endl;
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
};
int main(){
    Heap h;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        h.insert(x);
    }
    h.print();
    // cout << h.extractMax() << endl;
    // h.print();
    // cout << h.extractMax() << endl;
    // h.print();
    h.increase(4, 10);
    h.print();
    h.change(5, 100);
    h.print();
}