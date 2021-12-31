#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        int n;
        cin >> n;
        vector<tuple<int, int, string>> inven;
        string item;
        int p, q, m;
        for(int i = 0; i < n; i++){
            cin >> m;
            for(int j = 0; j < m; j++){
                cin >> item >> p >> q;
                inven.push_back(make_tuple(p,q,item));
            }
        }
        sort(inven.begin(),inven.end());//for(auto x : inven) cout << get<0>(x) <<  " " << get<1>(x) << " " << get<2>(x) << endl;
        int r;
        int sum = 0;
        cin >> r;
        for(int i = 0; i < r; i++){
            cin >> item >> q;
            for(auto x : inven){
                if(get<2>(x) == item){
                    sum += get<0>(x) * min(q, get<1>(x));
                    q -= min(q, get<1>(x));
                    if(q <= 0) break;
                }
            }
        }
        cout << sum << '\n';
    }
}