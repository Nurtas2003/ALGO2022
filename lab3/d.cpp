#include <bits/stdc++.h>

using namespace std;

pair<int , int> getRange(vector<int> &num, int ll, int rr) {
    pair<int, int> res = make_pair(-1, -2);

    if(num.back() < ll || num[0] > rr)
        return res;

    int l = -1, r = num.size()-1;

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(num[mid] >= ll)
            r = mid;
        else
            l = mid;
    }
    res.first = r;

    l = 0;
    r = num.size();

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(num[mid] <= rr)
            l = mid;
        else
            r = mid;
    }

    res.second = l;

    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> num(n);
    for(int i = 0 ; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        pair<int, int> Range1 = getRange(num, l1, r1);
        pair<int, int> Range2 = getRange(num, l2, r2);
        int c = 0;
        c += max(0, Range1.second - Range1.first + 1);
        c += max(0, Range2.second - Range2.first + 1);
        if(Range1.second >= Range2.second && Range1.first <= Range2.first)
            c -= max(0, Range2.second - Range2.first + 1);
        else if(Range2.second >= Range1.second && Range2.first <= Range1.first)
            c -= max(0, Range1.second - Range1.first + 1);
        else if(Range1.first <= Range2.first && Range1.second >= Range2.first)
            c -= max(0, Range1.second - Range2.first + 1);
        else if(Range2.first <= Range1.first && Range2.second >= Range1.first)
            c -= max(0, Range2.second - Range1.first + 1);
        cout << c << endl;
    }

    return 0;
}