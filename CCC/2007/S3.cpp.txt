#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    map<int, vector<int>> adj;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    while(true){
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        map<int,int> dist;
        map<int,int> vis;
        for(auto u : adj){
            dist[u.first] = 0;
            vis[u.first] = false;
        }
        int connected = false;
        int cycle = false;
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            int s = q.front(); q.pop();
            for(auto u : adj[s]){
                if(u == y) connected = true;
                if(u == x) cycle = true;
                if(cycle && connected) goto done;
                if(vis[u]) continue;
                q.push(u);
                dist[u] = dist[s] + 1;
                vis[u] = true;
            }
        }
        done:;
        if(connected && cycle) cout << "Yes " << dist[y] - 1 << "\n";
        else cout << "No\n";
    }
}