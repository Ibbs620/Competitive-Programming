#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, p, q;
    cin >> n >> m;
    vector<int> g[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 0; i <= n; i++) if(g[i].empty()) g[i].push_back(0);
    cin >> p >> q;

    stack<int> q1, q2;
    int s = p;
    int e = q;
    q1.push(s);
    q2.push(e);
    bool v1[n + 1] = {0}, v2[n + 1] = {0};
    v1[s] = 1, v2[e] = 1;
    while(!q1.empty()){
        s = q1.top();
        q1.pop();
        for(int x : g[s]){
            if(x == q){
                cout << "yes";
                return 0;
            }
            if(v1[x]) continue;
            v1[x] = 1;
            q1.push(x);
        }
    }
    while(!q2.empty()){
        e = q2.top();
        q2.pop();
        for(int x : g[e]){
            if(x == p){
                cout << "no";
                return 0;
            }
            if(v2[x]) continue;
            v2[x] = 1;
            q2.push(x);
        }
    }
    cout << "unknown";
}