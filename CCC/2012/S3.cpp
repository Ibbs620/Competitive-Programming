#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int r[n];
    int dif = 0;
    multiset<int> ms;
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> r[i];
        ms.insert(r[i]);
        s.insert(r[i]);
    }
    vector<pair<int,int>> v;
    for(auto x : s){
        v.push_back({ms.count(x), x});
    }
    sort(v.rbegin(), v.rend());
    auto a = v[0];
    dif = abs(a.second - v[1].second);
    for(int i = 2; i < v.size(); i++){
        if(v[i].first != v[i-1].first) break;
        dif = max(dif, abs(a.second - v[i].second));
    }
    cout << dif;
}
