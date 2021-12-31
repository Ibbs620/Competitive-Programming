//NOTE: This solution is incomplete. Only 15/50 points were achieved.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i = 0; i < m; i++){
        int s, d, l;
        cin >> s >> d >> l;
        adj[s].push_back({d, l});
    }
    int dist[n];
    bool vis[n];
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        dist[i] = 0;
        vis[i] = false;
    }

    dist[0] = 0;
    q.push({0,0});
    while(!q.empty()){
        int x = q.top().second; q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto u : adj[x]){
            int a = u.first, w = u.second;
            if(dist[x] + w > dist[a]){
                dist[a] = dist[x] + w;
                q.push({dist[a], a});
            }
        }
    }
    cout << dist[n-1];
}
