//NOTE: This solution is incomplete. Only 13/15 points were achieved.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, n, m;
    cin >> k >> n >> m;
    vector<tuple<int,int,int>> adj[n + 1];

    for(int i = 0; i < m; i++){
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back(make_tuple(b,t,h));
        adj[b].push_back(make_tuple(a,t,h));
    }
    int x, y;
    cin >> x >> y;

    int time[n+1];
    int wear[n+1];
    for(int i = 0; i <= n; i++) {
            time[i] = 2147483647;
            wear[i] = 2147483647;
    }
    time[x] = 0;
    wear[x] = 0;

    priority_queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,x));

    bool processed[n+1] = {false};

    while(!q.empty()){
        int a = get<2>(q.top()); q.pop();
        if(processed[a] == true) continue;
        processed[a] = true;
        for(auto u : adj[a]) {
            int b = get<0>(u), w = get<1>(u), d = get<2>(u);
            if(wear[a] + d < k){
                time[b] = min(time[b], time[a] + w);
                wear[b] = wear[a] + d;
                q.push(make_tuple(-1 * time[b], wear[b], b));
            }
        }
    }
    if(wear[y] < k) cout << time[y] << '\n';
    else cout << -1 << '\n';
}
