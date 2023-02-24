#include <iostream>
#include <vector>
using namespace std;

bool comp(string &s, string &t){
    string year_s = s.substr(6, 4);
    string year_t = t.substr(6, 4);
    if (year_s.compare(year_t) != 0) {    // если они не равны
        if (year_s.compare(year_t) < 0)     // если year_s<year_t 
            return true;
        return false;
    }
    // if(year_s > year_t) return true;
    // if(year_s < year_t) return false;
    string month_s = s.substr(3, 2);
    string month_t = t.substr(3, 2);
    if (month_s.compare(month_t) != 0) {
        if (month_s.compare(month_t) < 0)
            return true;
        return false;
    }
    // if(month_s > month_t) return true;
    // if(month_s < month_t) return false;
    string day_s = s.substr(0, 2);
    string day_t = t.substr(0, 2);
    if (day_s.compare(day_t) != 0) {
        if (day_s.compare(day_t) < 0)
            return true;
        return false;
    }
    // if(day_s > day_t) return true;
    // if(day_s < day_t) return false;
}

int partition(vector<string> &v, int l, int h){
    string p = v[h];
    int i=l-1;
    for(int j=l; j<=h-1; j++){
        if(comp(p, v[j])){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[h]);
    return i+1;
}

void quickSort(vector<string> &v, int l, int h){
    if(l<h){
        int pi=partition(v, l, h);
        quickSort(v, l, pi-1);
        quickSort(v, pi+1, h);
    }
}

int main(){
    int n; cin >> n;
    vector<string>v;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    
    quickSort(v, 0, v.size()-1);

    // for(int i=0; i<v.size(); i++){     
    //     cout << v[i] << endl;;          наоборот шыкты ен улкени биринши
    // }

    for(int i=v.size()-1; i>=0; i--){    
        cout << v[i] << endl;;
    }
}